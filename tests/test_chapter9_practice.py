"""Integration checks for independently authored content and saved mini-challenges."""

import shutil
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from tools import chapter9_steps, course, course_web


class ChapterNinePracticeTest(unittest.TestCase):
    def test_source_coverage_and_exercise_provenance_are_traceable(self):
        for lesson in course_web.chapter_lessons():
            document = chapter9_steps.DOCUMENTS[lesson['id']]
            self.assertEqual(document['sourceUrl'], lesson['url'])
            steps = document['steps']
            suffixes = {step['suffix'] for step in steps}
            self.assertEqual(len(suffixes), len(steps))
            self.assertTrue(document['coverage'])
            for item in document['coverage']:
                self.assertTrue(item['concept'])
                self.assertTrue(item['steps'])
                self.assertLessEqual(set(item['steps']), suffixes)
            for step in steps:
                self.assertTrue(step['sourceExercise'])
                self.assertRegex(step['suffix'], r'^[a-z][a-z0-9-]*$')
            self.assertEqual(steps[-1]['suffix'], 'code')
            self.assertNotIn('practice', steps[-1])

    def test_open_and_save_practice_preserve_existing_work_and_parent(self):
        step = next(item for item in course_web.activities() if item.get('practice'))
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            with patch.object(course, 'ROOT', root), patch.object(course, 'WORKSPACES', root / 'workspaces'), \
                    patch.object(course, 'save_progress') as progress, patch.object(course, 'sync_repository') as sync:
                parent = course.workspace_path(course.lesson_by_id(step['lessonId'])) / 'main.cpp'
                parent.parent.mkdir(parents=True)
                parent.write_text('parent work')
                content = course_web.activity_content(step)
                path = root / content['path']
                self.assertEqual(path.read_text(), step['practice']['starter'])
                self.assertTrue(content['practice'])
                self.assertEqual(content['id'], step['id'])
                course_web.save_source(content, {'source': 'saved mini draft', 'revision': content['revision']})
                self.assertEqual(course_web.activity_content(step)['source'], 'saved mini draft')
                self.assertEqual(parent.read_text(), 'parent work')
                with self.assertRaises(course_web.SaveConflict):
                    course_web.save_source(content, {'source': 'stale overwrite', 'revision': content['revision']})
                self.assertEqual(path.read_text(), 'saved mini draft')
                progress.assert_not_called()
                sync.assert_not_called()

    def test_practice_paths_reject_external_symlink(self):
        step = next(item for item in course_web.activities() if item.get('practice'))
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            with patch.object(course, 'WORKSPACES', root / 'workspaces'):
                external = root / 'external'
                external.mkdir()
                path = course_web.source_path(course_web.practice_descriptor(step))
                path.parent.parent.mkdir(parents=True)
                path.parent.symlink_to(external, target_is_directory=True)
                with self.assertRaises(ValueError):
                    course_web.ensure_practice(step)
                self.assertEqual(list(external.iterdir()), [])

    @unittest.skipUnless(shutil.which('g++'), 'g++ is required')
    def test_all_mini_starters_fail_and_solutions_pass_the_actual_runner(self):
        with tempfile.TemporaryDirectory() as directory, \
                patch.object(course, 'WORKSPACES', Path(directory)):
            for step in course_web.activities():
                if not step.get('practice'):
                    continue
                with self.subTest(activity=step['id']):
                    path = course_web.ensure_practice(step)
                    starter = course_web.run_practice_tests(step)
                    self.assertFalse(starter['passed'], starter['message'])
                    path.write_text(step['practice']['solution'])
                    solution = course_web.run_practice_tests(step)
                    self.assertTrue(solution['passed'], solution['message'])


if __name__ == '__main__':
    unittest.main()
