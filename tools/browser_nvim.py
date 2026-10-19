"""A small real-Neovim remote UI bridge (optional msgpack dependency).

Uses Neovim's documented MessagePack RPC + ext_linegrid protocol, not terminal
escape emulation. Only user-initiated browser requests create or edit a session.
"""

import shutil
import subprocess
import threading

try:
    import msgpack
except ImportError:
    msgpack = None


def available():
    return bool(msgpack is not None and shutil.which('nvim'))


class NvimSession:
    def __init__(self, path, cols=90, rows=30):
        if not available():
            raise RuntimeError('Embedded Neovim needs nvim and Python msgpack. You can still edit in your own Neovim.')
        self.lock = threading.RLock()
        self.write_lock = threading.Lock()
        self.pending = {}
        self.counter = 0
        self.width, self.height = cols, rows
        self.grid = [[(' ', 0) for _ in range(cols)] for _ in range(rows)]
        self.highlights = {}
        self.cursor = [0, 0]
        self.mode = 'normal'
        self.error = None
        self.process = subprocess.Popen(
            [shutil.which('nvim'), '--embed', '--clean', '-n', str(path)],
            cwd=path.parent, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL,
        )
        self.reader = threading.Thread(target=self.read, daemon=True)
        self.reader.start()
        try:
            self.call('nvim_ui_attach', [cols, rows, {'rgb': True, 'ext_linegrid': True}])
            self.call('nvim_command', ['set termguicolors number noswapfile nowrap laststatus=2'])
            self.call('nvim_command', ['silent! colorscheme habamax'])
            self.call('nvim_command', [r'silent! /\v\/\/ TODO:/'])
            self.call('nvim_command', ['normal! zz'])
        except Exception:
            self.close()
            raise

    def call(self, method, args):
        with self.lock:
            self.counter += 1
            request_id = self.counter
            response = {'event': threading.Event()}
            self.pending[request_id] = response
        try:
            with self.write_lock:
                self.process.stdin.write(msgpack.packb([0, request_id, method, args], use_bin_type=True))
                self.process.stdin.flush()
            if not response['event'].wait(5):
                raise RuntimeError('Neovim is busy or has closed. Save work in any active session before reconnecting.')
            if response.get('error'):
                raise RuntimeError(str(response['error']))
            return response.get('result')
        finally:
            with self.lock:
                self.pending.pop(request_id, None)

    def read(self):
        unpacker = msgpack.Unpacker(raw=False, strict_map_key=False)
        try:
            while True:
                data = self.process.stdout.read1(65536)
                if not data:
                    break
                unpacker.feed(data)
                for message in unpacker:
                    with self.lock:
                        if message[0] == 1:
                            response = self.pending.get(message[1])
                            if response is not None:
                                response.update(error=message[2], result=message[3])
                                response['event'].set()
                        elif message[0] == 2 and message[1] == 'redraw':
                            self.redraw(message[2])
        except (OSError, ValueError) as error:
            self.error = str(error)
        finally:
            with self.lock:
                self.error = self.error or 'Neovim closed. Saved files are still on disk.'
                for response in self.pending.values():
                    response['error'] = self.error
                    response['event'].set()

    def redraw(self, events):
        for event in events:
            name = event[0]
            for args in event[1:]:
                if name == 'grid_resize' and args[0] == 1:
                    self.width, self.height = args[1:3]
                    self.grid = [[(' ', 0) for _ in range(self.width)] for _ in range(self.height)]
                elif name == 'grid_clear' and args[0] == 1:
                    self.grid = [[(' ', 0) for _ in range(self.width)] for _ in range(self.height)]
                elif name == 'grid_line' and args[0] == 1:
                    _, row, column, cells, *_ = args
                    highlight = 0
                    for cell in cells:
                        if len(cell) > 1:
                            highlight = cell[1]
                        repeat = cell[2] if len(cell) > 2 else 1
                        for _ in range(repeat):
                            if 0 <= row < self.height and 0 <= column < self.width:
                                self.grid[row][column] = (cell[0], highlight)
                            column += 1
                elif name == 'grid_scroll' and args[0] == 1:
                    _, top, bottom, left, right, rows, cols = args
                    old = [line[:] for line in self.grid]
                    for row in range(top, bottom):
                        for col in range(left, right):
                            src_row, src_col = row + rows, col + cols
                            self.grid[row][col] = old[src_row][src_col] if top <= src_row < bottom and left <= src_col < right else (' ', 0)
                elif name == 'grid_cursor_goto' and args[0] == 1:
                    self.cursor = args[1:3]
                elif name == 'hl_attr_define':
                    self.highlights[args[0]] = args[1]
                elif name == 'mode_change':
                    self.mode = args[0]

    def snapshot(self):
        with self.lock:
            return {'grid': [line[:] for line in self.grid], 'cursor': self.cursor[:],
                    'highlights': dict(self.highlights), 'mode': self.mode,
                    'width': self.width, 'height': self.height, 'error': self.error}

    def close(self):
        if self.process.poll() is None:
            self.process.terminate()
            try:
                self.process.wait(timeout=2)
            except subprocess.TimeoutExpired:
                self.process.kill()
                self.process.wait(timeout=2)
        self.reader.join(timeout=2)
        self.process.stdin.close()
        self.process.stdout.close()
