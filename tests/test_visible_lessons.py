import shutil
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from tools.course import SOLUTIONS, STARTERS, compile_and_run, load_lessons


class VisibleLessonTest(unittest.TestCase):
    def lessons(self):
        return [lesson for lesson in load_lessons() if lesson.get('visibleTests')]

    def test_visible_tests_match_independent_checker(self):
        self.assertEqual(len(self.lessons()), 61)
        for lesson in self.lessons():
            with self.subTest(lesson=lesson['id']):
                driver = (ROOT / lesson['behaviorTests'][0]).read_text()
                assertions = driver[driver.index('int main()'):]
                for directory in (STARTERS / lesson['key'], SOLUTIONS / lesson['key']):
                    main = (directory / 'main.cpp').read_text()
                    self.assertIn(assertions, main)
                    self.assertTrue((directory / 'lesson.md').is_file())
                    self.assertTrue((directory / 'hints.md').is_file())
                    self.assertEqual((directory / 'lab_checks.h').read_text(),
                                     (ROOT / 'tests/lesson_cases/lab_checks.h').read_text())

    @unittest.skipUnless(shutil.which('g++'), 'g++ is required')
    def test_every_visible_reference_runs_without_stdin(self):
        with tempfile.TemporaryDirectory() as directory:
            executable = Path(directory) / 'visible'
            for lesson in self.lessons():
                with self.subTest(lesson=lesson['id']):
                    source = SOLUTIONS / lesson['key']
                    build = subprocess.run(
                        ['g++', '-std=c++20', '-UNDEBUG', *[str(source / name) for name in lesson['sources']],
                         '-o', str(executable)], capture_output=True, text=True, timeout=30)
                    self.assertEqual(build.returncode, 0, build.stderr)
                    run = subprocess.run([str(executable)], input='', capture_output=True, text=True, timeout=5)
                    self.assertEqual(run.returncode, 0, run.stderr)
                    self.assertIn('tests passed', run.stdout)

    @unittest.skipUnless(shutil.which('g++'), 'g++ is required')
    def test_editing_visible_tests_does_not_change_submission_tests(self):
        lesson = next(lesson for lesson in self.lessons() if lesson['id'] == '9.1')
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory)
            shutil.copytree(STARTERS / lesson['key'], source, dirs_exist_ok=True)
            main = (source / 'main.cpp').read_text()
            main = main[:main.index('// ==================== VISIBLE TESTS')]
            (source / 'main.cpp').write_text(main + '\n#ifndef COURSE_TESTING\nint main() { return 0; }\n#endif\n')
            passed, message = compile_and_run(lesson, source)
            self.assertFalse(passed)
            self.assertIn('2024', message)

    @unittest.skipUnless(shutil.which('cmake') and shutil.which('g++'), 'CMake and g++ are required')
    def test_standalone_multifile_and_assertion_cmake_targets(self):
        for key in ('09_06', '11_10'):
            with self.subTest(lesson=key), tempfile.TemporaryDirectory() as directory:
                configure = subprocess.run(
                    ['cmake', '-S', str(SOLUTIONS / key), '-B', directory, '-DCMAKE_BUILD_TYPE=Release'],
                    capture_output=True, text=True, timeout=30)
                self.assertEqual(configure.returncode, 0, configure.stderr)
                build = subprocess.run(['cmake', '--build', directory], capture_output=True, text=True, timeout=30)
                self.assertEqual(build.returncode, 0, build.stderr)
                run = subprocess.run([str(Path(directory) / f'lesson_{key}')], input='',
                                     capture_output=True, text=True, timeout=5)
                self.assertEqual(run.returncode, 0, run.stderr)
                self.assertIn('tests passed', run.stdout)
