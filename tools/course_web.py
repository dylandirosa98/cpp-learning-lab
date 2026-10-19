"""Local Chapter 9 companion with live LearnCpp and a Vim-keyed browser editor."""

import argparse
import hashlib
import json
import os
import secrets
import subprocess
import sys
import tempfile
import threading
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import urlsplit

from tools import chapter9_steps, course

ASSETS = Path(__file__).parent / 'web'
MAX_BODY = 2_000_000
VENDOR_FILES = {'codemirror.min.js', 'codemirror.min.css', 'vim.min.js',
                'clike.min.js', 'material-darker.min.css', 'dialog.min.js', 'dialog.min.css', 'LICENSE'}


def revision(source):
    return hashlib.sha256(source).hexdigest()


class SaveConflict(ValueError):
    pass


def save_source(lesson, payload):
    """Save only the fixed main.cpp, with optimistic locking against outside edits."""
    source, base = payload.get('source'), payload.get('revision')
    if not isinstance(source, str) or not isinstance(base, str):
        raise ValueError('Source and its original revision are required.')
    encoded = source.encode('utf-8')
    if len(encoded) > 1_000_000:
        raise ValueError('Challenge source is too large (limit: 1 MB).')
    path = course.workspace_path(lesson) / 'main.cpp'
    if path.is_symlink() or not path.resolve().is_relative_to(course.WORKSPACES.resolve()):
        raise ValueError('The browser can save only regular challenge files inside workspaces.')
    current = path.read_bytes()
    if revision(current) != base and current != encoded:
        raise SaveConflict('This file changed on disk. Your browser draft is intact. Copy it before reloading the disk file to reconcile the changes.')
    if current != encoded:
        # Replace atomically so a reader never sees a half-written source file.
        temporary = None
        try:
            with tempfile.NamedTemporaryFile(dir=path.parent, prefix='.browser-save-', delete=False) as handle:
                temporary = Path(handle.name)
                handle.write(encoded)
            temporary.chmod(path.stat().st_mode & 0o777)
            os.replace(temporary, path)
        finally:
            if temporary is not None:
                temporary.unlink(missing_ok=True)
    return {'revision': revision(encoded), 'saved': True}


def chapter_lessons():
    return [lesson for lesson in course.load_lessons() if lesson['id'].startswith('9.')]


def lesson_content(lesson):
    directory = course.workspace_path(lesson)
    source = (directory / 'main.cpp').read_bytes()
    solution_dir = course.SOLUTIONS / lesson['key']
    quiz_items = [
        {'question': q, 'options': opts, 'answer': ans, 'explanation': exp}
        for q, opts, ans, exp in chapter9_steps.QUIZZES.get(lesson['id'], [])
    ]
    return {
        'id': lesson['id'],
        'title': lesson['title'],
        'minutes': lesson['estimatedMinutes'],
        'challenge': lesson['challenge'],
        'examples': lesson['expectedOutput'],
        'hints': lesson['hints'],
        'url': lesson['url'],
        'notes': (directory / 'lesson.md').read_text(),
        'source': source.decode('utf-8'),
        'revision': revision(source),
        'solution': (solution_dir / 'main.cpp').read_text() if (solution_dir / 'main.cpp').exists() else '',
        'path': str((directory / 'main.cpp').relative_to(course.ROOT)),
        'completed': lesson['key'] in course.load_progress().get('completed', []),
        'quizzes': quiz_items,
    }


def run_saved_tests(lesson_id):
    # A separate process gives compilation + execution an overall time limit.
    # Its private build directory cannot race with Alt+R or ./course check.
    try:
        result = subprocess.run(
            [sys.executable, '-m', 'tools.course_web', '--test', lesson_id],
            cwd=course.ROOT, capture_output=True, text=True, timeout=40,
        )
    except subprocess.TimeoutExpired:
        return {'passed': False, 'message': 'Testing exceeded 40 seconds. Check for an infinite loop or compilation problem.'}
    if result.returncode != 0:
        return {'passed': False, 'message': 'Could not run tests.\n' + result.stderr[-24000:]}
    return json.loads(result.stdout)


class CourseServer(ThreadingHTTPServer):
    daemon_threads = True

    def __init__(self, address, runner=run_saved_tests):
        self.token = secrets.token_urlsafe(32)
        self.test_lock = threading.Lock()
        self.source_lock = threading.Lock()
        self.runner = runner
        super().__init__(address, CourseHandler)

    @property
    def origin(self):
        return f'http://127.0.0.1:{self.server_port}'


class CourseHandler(BaseHTTPRequestHandler):
    def log_message(self, format, *args):
        # The terminal remains focused on launch instructions, not asset requests.
        pass

    def respond(self, status, body, content_type='application/json; charset=utf-8'):
        if not isinstance(body, bytes):
            body = json.dumps(body).encode()
        self.send_response(status)
        self.send_header('Content-Type', content_type)
        self.send_header('Content-Length', str(len(body)))
        self.send_header('Cache-Control', 'no-store')
        self.send_header('X-Content-Type-Options', 'nosniff')
        self.send_header('Referrer-Policy', 'no-referrer')
        self.send_header(
            'Content-Security-Policy',
            "default-src 'self'; script-src 'self'; style-src 'self' 'unsafe-inline'; connect-src 'self'; img-src 'self' data:; frame-src 'self' https://www.learncpp.com; frame-ancestors 'none'; base-uri 'none'; form-action 'none'",
        )
        self.end_headers()
        self.wfile.write(body)

    def valid_host(self):
        # Reject DNS rebinding; do not expose local source or execution to other sites.
        if self.headers.get('Host') != urlsplit(self.server.origin).netloc:
            self.respond(421, {'error': 'Open the exact 127.0.0.1 URL printed in the terminal.'})
            return False
        return True

    def read_json(self):
        length = int(self.headers.get('Content-Length', '0') or '0')
        if length < 0 or length > MAX_BODY:
            raise ValueError('Request body is too large.')
        if length == 0:
            return {}
        payload = json.loads(self.rfile.read(length).decode('utf-8'))
        if not isinstance(payload, dict):
            raise ValueError('Expected a JSON object.')
        return payload

    def do_GET(self):
        if not self.valid_host():
            return
        path = urlsplit(self.path).path
        if path == '/api/course':
            lessons = chapter_lessons()
            completed = set(course.load_progress().get('completed', []))
            self.respond(200, {
                'token': self.server.token,
                'lessons': [
                    {
                        'id': lesson['id'],
                        'title': lesson['title'],
                        'minutes': lesson['estimatedMinutes'],
                        'url': lesson['url'],
                        'completed': lesson['key'] in completed,
                    }
                    for lesson in lessons
                ],
                'steps': chapter9_steps.steps_for(lessons),
            })
        elif path.startswith('/api/lessons/'):
            lesson = next((item for item in chapter_lessons() if path == '/api/lessons/' + item['id']), None)
            if lesson is None:
                self.respond(404, {'error': 'Only Chapter 9 is available in this browser companion.'})
                return
            try:
                self.respond(200, lesson_content(lesson))
            except OSError:
                self.respond(409, {'error': 'Lesson files are missing. Run ./course setup and refresh.'})
        else:
            assets = {'/': ('index.html', 'text/html; charset=utf-8'),
                      '/app.js': ('app.js', 'text/javascript; charset=utf-8'),
                      '/style.css': ('style.css', 'text/css; charset=utf-8')}
            vendor_prefix = '/vendor/codemirror-5.65.16/'
            if path.startswith(vendor_prefix) and path[len(vendor_prefix):] in VENDOR_FILES:
                name = path[len(vendor_prefix):]
                mime = 'text/javascript' if name.endswith('.js') else 'text/css' if name.endswith('.css') else 'text/plain'
                self.respond(200, (ASSETS / 'vendor/codemirror-5.65.16' / name).read_bytes(), mime + '; charset=utf-8')
                return
            if path not in assets:
                self.respond(404, {'error': 'Not found'})
                return
            filename, mime = assets[path]
            self.respond(200, (ASSETS / filename).read_bytes(), mime)

    def do_POST(self):
        if not self.valid_host():
            return
        if (self.headers.get('Origin') not in (None, self.server.origin)
                or not secrets.compare_digest(self.headers.get('X-Course-Token', ''), self.server.token)):
            self.respond(403, {'error': 'Refresh the companion and try again.'})
            return
        path = urlsplit(self.path).path
        if path.startswith('/api/save/'):
            lesson_id = path[len('/api/save/'):]
            lesson = next((item for item in chapter_lessons() if item['id'] == lesson_id), None)
            if lesson is None:
                self.respond(404, {'error': 'Unknown Chapter 9 save route.'})
                return
            try:
                payload = self.read_json()
                with self.server.source_lock:
                    result = save_source(lesson, payload)
                self.respond(200, result)
            except SaveConflict as error:
                self.respond(409, {'error': str(error)})
            except (ValueError, UnicodeError) as error:
                self.respond(400, {'error': str(error)})
            except OSError:
                self.respond(500, {'error': 'Could not save the challenge. Your browser draft is intact.'})
            return

        lesson = next((item for item in chapter_lessons() if path == '/api/test/' + item['id']), None)
        if lesson is None:
            self.respond(404, {'error': 'Unknown Chapter 9 test route.'})
            return
        if not self.server.test_lock.acquire(blocking=False):
            self.respond(409, {'error': 'A test run is already in progress. Wait for it to finish.'})
            return
        try:
            payload = self.read_json()
            if 'revision' in payload:
                with self.server.source_lock:
                    current = (course.workspace_path(lesson) / 'main.cpp').read_bytes()
                if payload['revision'] != revision(current):
                    self.respond(409, {'error': 'The file changed after saving; tests were not run. Reconcile your draft with the disk file first.'})
                    return
            self.respond(200, self.server.runner(lesson['id']))
        except (OSError, ValueError):
            self.respond(500, {'error': 'The test runner failed. Try ./course check from the terminal.'})
        finally:
            self.server.test_lock.release()



def serve(port=8765):
    for lesson in chapter_lessons():
        course.ensure_workspace(lesson, announce=False)
    try:
        server = CourseServer(('127.0.0.1', port))
    except OSError as error:
        raise SystemExit(f'Could not start browser companion: {error}. Try ./course web --port 8766.') from error
    print(f'\nChapter 9 browser companion: {server.origin}', flush=True)
    print('Browser editor: Vim keys, :w to save, Alt+R to save and run tests. Submit in your terminal as usual.')
    print('Local only. Saves update main.cpp; practice never saves completion or syncs. Ctrl+C to stop.', flush=True)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print('\nCompanion stopped.')
    finally:
        server.server_close()


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--test', required=True)
    args = parser.parse_args()
    lesson = next((item for item in chapter_lessons() if item['id'] == args.test), None)
    if lesson is None:
        raise SystemExit('Only Chapter 9 is supported.')
    course.STATE.mkdir(exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='web-tests-', dir=course.STATE) as directory:
        course.BUILD = Path(directory)
        passed, message = course.compile_and_run(lesson, course.workspace_path(lesson))
    print(json.dumps({'passed': passed, 'message': message[-24000:]}))
