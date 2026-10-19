import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from tools.course import SOLUTIONS, STARTERS, compile_and_run, load_lessons  # noqa: E402


class BehavioralLessonTest(unittest.TestCase):
    def test_function_challenges_use_behavior_drivers(self):
        for lesson in load_lessons():
            revised = lesson['key'].startswith('08_') and lesson['key'] not in {
                '08_01', '08_02', '08_03', '08_04'
            }
            revised = revised or lesson['id'].split('.')[0] in {'9', '10', '11', '12', '13'}
            with self.subTest(lesson=lesson['id']):
                self.assertEqual(bool(lesson.get('behaviorTests')), revised)
                if revised:
                    self.assertEqual(lesson['sourceChecks'], [])
                    for driver in lesson['behaviorTests']:
                        self.assertTrue((ROOT / driver).is_file())

    @unittest.skipUnless(shutil.which('g++'), 'g++ is required')
    def test_reference_implementations_pass_and_empty_starters_fail(self):
        for lesson in load_lessons():
            if not lesson.get('behaviorTests'):
                continue
            with self.subTest(lesson=lesson['id']):
                passed, message = compile_and_run(lesson, SOLUTIONS / lesson['key'])
                self.assertTrue(passed, message)
                passed, message = compile_and_run(lesson, STARTERS / lesson['key'])
                self.assertFalse(passed, 'Unimplemented starter incorrectly passed')
                self.assertTrue('Behavioral tests failed' in message or 'Compilation failed' in message, message)

    @unittest.skipUnless(shutil.which('g++'), 'g++ is required')
    def test_alternative_implementation_and_console_text_are_not_rejected(self):
        lesson = next(item for item in load_lessons() if item['id'] == '8.5')
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory)
            (source / 'main.cpp').write_text('''
#include <iostream>
#include <string_view>
std::string_view statusMessage(int code) {
    std::cout << "debug text does not affect returned values\\n";
    if (code == 1) return "running";
    if (code == 2) return "paused";
    if (code == 3) return "stopped";
    return "unknown";
}
int main() { return 0; }
''')
            passed, message = compile_and_run(lesson, source)
            self.assertTrue(passed, message)

    @unittest.skipUnless(shutil.which('g++'), 'g++ is required')
    def test_main_output_cannot_fake_a_function_result(self):
        lesson = next(item for item in load_lessons() if item['id'] == '8.5')
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory)
            (source / 'main.cpp').write_text('''
#include <iostream>
#include <string_view>
std::string_view statusMessage(int) { return "running"; }
int main() { std::cout << "All behavioral tests passed.\\n"; return 0; }
''')
            passed, message = compile_and_run(lesson, source)
            self.assertFalse(passed)
            self.assertIn('expected unknown, got running', message)
