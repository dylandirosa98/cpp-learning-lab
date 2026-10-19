import json
import shutil
import sys
import threading
import tempfile
import unittest
from pathlib import Path
from unittest.mock import Mock, patch
from urllib.error import HTTPError
from urllib.request import Request, urlopen

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from tools import course, course_web


class CourseWebTest(unittest.TestCase):
    def setUp(self):
        self.runner = Mock(return_value={'passed': True, 'message': 'All behavioral tests passed.'})
        self.server = course_web.CourseServer(('127.0.0.1', 0), runner=self.runner)
        self.thread = threading.Thread(target=self.server.serve_forever, daemon=True)
        self.thread.start()

    def tearDown(self):
        self.server.shutdown()
        self.server.server_close()
        self.thread.join()

    def request(self, path, method='GET', headers=None, payload=None):
        data = json.dumps(payload).encode() if payload is not None else None
        request = Request(self.server.origin + path, method=method, headers=headers or {}, data=data)
        try:
            response = urlopen(request, timeout=5)
        except HTTPError as error:
            response = error
        with response:
            body = response.read().decode()
            return response.status, response.headers, body

    def test_catalog_exposes_only_chapter_nine_and_real_progress(self):
        with patch.object(course, 'load_progress', return_value={'completed': ['09_01', '10_01']}):
            status, headers, body = self.request('/api/course')
        self.assertEqual(status, 200)
        data = json.loads(body)
        self.assertEqual([item['id'] for item in data['lessons']], ['9.1', '9.2', '9.3', '9.4', '9.5', '9.6', '9.x'])
        self.assertEqual(len(data['steps']), 29)
        self.assertEqual(data['steps'][0]['id'], '9.1-idea')
        self.assertEqual(data['steps'][0]['kind'], 'read')
        self.assertEqual(data['steps'][1]['id'], '9.1-quiz')
        self.assertTrue(data['lessons'][0]['completed'])
        self.assertFalse(data['lessons'][1]['completed'])
        self.assertEqual(data['token'], self.server.token)
        self.assertEqual(headers['Cache-Control'], 'no-store')

    def test_lesson_is_a_snapshot_of_the_existing_workspace(self):
        status, _, body = self.request('/api/lessons/9.1')
        data = json.loads(body)
        self.assertEqual(status, 200)
        self.assertEqual(data['source'], (ROOT / data['path']).read_text())
        self.assertEqual(data['url'], 'https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/')
        self.assertEqual(len(data['quizzes']), 2)
        self.assertIn('Worked example', data['notes'])
        self.assertIn('isLeapYear', data['challenge'])
        self.assertEqual(len(data['hints']), 3)

    def test_assets_are_served_with_csp_allowing_learncpp_frame(self):
        for route, mime in [('/', 'text/html'), ('/app.js', 'text/javascript'), ('/style.css', 'text/css')]:
            with self.subTest(route=route):
                status, headers, _ = self.request(route)
                self.assertEqual(status, 200)
                self.assertIn(mime, headers['Content-Type'])
                self.assertIn("frame-src 'self' https://www.learncpp.com", headers['Content-Security-Policy'])
                self.assertIn("frame-ancestors 'none'", headers['Content-Security-Policy'])
                self.assertNotIn('Access-Control-Allow-Origin', headers)

    def test_arbitrary_files_and_other_chapters_are_not_exposed(self):
        for path in ['/api/lessons/10.1', '/api/lessons/../../.course/progress.json',
                     '/.git/config', '/tools/course.py', '/solutions/09_01/main.cpp']:
            self.assertEqual(self.request(path)[0], 404, path)

    def test_mutating_or_foreign_test_routes_do_not_run_anything(self):
        for path in ['/api/test/10.1', '/api/submit/9.1', '/api/reset/9.1', '/api/test/../../etc/passwd']:
            self.assertEqual(self.request(path, 'POST', {'X-Course-Token': self.server.token})[0], 404)
        self.runner.assert_not_called()

    def test_running_tests_never_saves_progress_or_syncs(self):
        with patch.object(course, 'save_progress') as save, patch.object(course, 'sync_repository') as sync:
            status, _, body = self.request('/api/test/9.1', 'POST', {
                'X-Course-Token': self.server.token, 'Origin': self.server.origin})
        self.assertEqual(status, 200)
        self.assertTrue(json.loads(body)['passed'])
        self.runner.assert_called_once_with('9.1')
        save.assert_not_called()
        sync.assert_not_called()

    def test_execution_requires_token_and_rejects_foreign_origin_and_host(self):
        for headers in [{}, {'X-Course-Token': 'wrong'},
                        {'X-Course-Token': self.server.token, 'Origin': 'https://evil.example'}]:
            self.assertEqual(self.request('/api/test/9.1', 'POST', headers)[0], 403)
        self.assertEqual(self.request('/api/course', headers={'Host': 'evil.example'})[0], 421)
        self.assertEqual(self.request('/api/test/9.1', 'POST', {
            'Host': 'evil.example', 'X-Course-Token': self.server.token})[0], 421)
        self.runner.assert_not_called()

    def test_parallel_test_run_is_rejected(self):
        with self.server.test_lock:
            self.assertEqual(self.request('/api/test/9.1', 'POST', {'X-Course-Token': self.server.token})[0], 409)
        self.runner.assert_not_called()

    def test_runner_errors_are_reported_and_release_the_lock(self):
        self.runner.side_effect = ValueError('bad output')
        status, _, body = self.request('/api/test/9.1', 'POST', {'X-Course-Token': self.server.token})
        self.assertEqual(status, 500)
        self.assertIn('test runner failed', json.loads(body)['error'])
        self.assertFalse(self.server.test_lock.locked())

    @unittest.skipUnless(shutil.which('g++'), 'g++ is required')
    def test_real_saved_code_runs_without_modifying_files_or_progress(self):
        files = [course.PROGRESS_FILE, ROOT / 'workspaces/09/09_01/main.cpp']
        before = {path: path.read_bytes() for path in files}
        result = course_web.run_saved_tests('9.1')
        self.assertIsInstance(result['passed'], bool)
        self.assertTrue(result['message'])
        self.assertEqual(before, {path: path.read_bytes() for path in files})

    def test_cli_accepts_web_and_custom_port(self):
        args = course.build_parser().parse_args(['web', '--port', '8766'])
        self.assertEqual(args.command, 'web')
        self.assertEqual(args.port, 8766)

    def test_step_sequences_are_curated_and_questions_are_valid(self):
        from tools.chapter9_steps import steps_for
        steps = steps_for(course_web.chapter_lessons())
        self.assertEqual(len({step['id'] for step in steps}), len(steps))
        self.assertEqual({step['kind'] for step in steps}, {'read', 'quiz', 'predict', 'debug', 'code'})
        self.assertEqual([step['kind'] for step in steps if step['lessonId'] == '9.5'],
                         ['read', 'predict', 'read', 'debug', 'read', 'predict', 'code'])
        self.assertEqual(len([step for step in steps if step['lessonId'] == '9.4']), 3)
        for step in steps:
            with self.subTest(step=step['id']):
                self.assertTrue(step['objective'])
                self.assertTrue(step['explanation'])
                questions = step.get('questions', [])
                if step['kind'] in {'quiz', 'predict', 'debug'}:
                    self.assertTrue(questions)
                else:
                    self.assertFalse(questions)
                if step['kind'] == 'debug':
                    self.assertIn('REPLACEMENT', step['repairTemplate'])
                    self.assertIn('BUG', step['code'])
                for question in questions:
                    self.assertGreaterEqual(question['answer'], 0)
                    self.assertLess(question['answer'], len(question['options']))
                    self.assertTrue(question['explanation'])

    def test_all_existing_file_challenges_remain_available(self):
        from tools.chapter9_steps import steps_for
        steps = steps_for(course_web.chapter_lessons())
        for lesson in course_web.chapter_lessons():
            self.assertEqual(len([step for step in steps if step['id'] == lesson['id'] + '-code']), 1)

    def test_save_updates_only_main_and_does_not_submit(self):
        with tempfile.TemporaryDirectory() as directory, patch.object(course, 'WORKSPACES', Path(directory)), \
                patch.object(course, 'save_progress') as save, patch.object(course, 'sync_repository') as sync:
            path = Path(directory) / '09/09_01/main.cpp'
            path.parent.mkdir(parents=True)
            path.write_text('old source')
            sibling = path.with_name('lesson.md')
            sibling.write_text('preserve me')
            source = '// π and a new line\nint main() {}\n'
            status, _, body = self.request('/api/save/9.1', 'POST', {'X-Course-Token': self.server.token},
                                           {'source': source, 'revision': course_web.revision(b'old source')})
            self.assertEqual(status, 200, body)
            self.assertEqual(path.read_text(), source)
            self.assertEqual(json.loads(body)['revision'], course_web.revision(source.encode()))
            self.assertEqual(sibling.read_text(), 'preserve me')
            self.assertEqual(list(path.parent.glob('.browser-save-*')), [])
            save.assert_not_called()
            sync.assert_not_called()
            self.runner.assert_not_called()

    def test_save_refuses_stale_revision_without_overwriting_external_work(self):
        with tempfile.TemporaryDirectory() as directory, patch.object(course, 'WORKSPACES', Path(directory)):
            path = Path(directory) / '09/09_01/main.cpp'
            path.parent.mkdir(parents=True)
            path.write_text('new external edits')
            status, _, _ = self.request('/api/save/9.1', 'POST', {'X-Course-Token': self.server.token},
                                        {'source': 'browser draft', 'revision': course_web.revision(b'old source')})
            self.assertEqual(status, 409)
            self.assertEqual(path.read_text(), 'new external edits')

    def test_save_requires_token_and_rejects_bad_payloads_and_other_files(self):
        self.assertEqual(self.request('/api/save/9.1', 'POST', payload={'source': 'bad'})[0], 403)
        for payload in [{}, {'source': 123, 'revision': 'old'}, {'source': 'x' * 1_000_001, 'revision': 'old'}]:
            self.assertEqual(self.request('/api/save/9.1', 'POST', {'X-Course-Token': self.server.token}, payload)[0], 400)
        for path in ['/api/save/10.1', '/api/save/9.1/../../progress.json', '/api/nvim/9.1']:
            self.assertEqual(self.request(path, 'POST', {'X-Course-Token': self.server.token}, {'source': 'bad'})[0], 404)

    def test_stale_test_revision_does_not_run_wrong_code(self):
        status, _, _ = self.request('/api/test/9.1', 'POST', {'X-Course-Token': self.server.token}, {'revision': 'stale'})
        self.assertEqual(status, 409)
        self.runner.assert_not_called()

    def test_all_editor_assets_are_local_and_allowlisted(self):
        for name in course_web.VENDOR_FILES:
            status, _, _ = self.request('/vendor/codemirror-5.65.16/' + name)
            self.assertEqual(status, 200, name)
        self.assertEqual(self.request('/vendor/codemirror-5.65.16/../../course.py')[0], 404)
