"""Optional real-browser Vim/Alt+R test, using disposable copies of all work.

Run: python3 tests/browser_editor.py (requires Playwright + Chromium + g++).
No user challenge files or completion records are modified.
"""

import shutil
import json
import sys
import tempfile
import threading
from pathlib import Path
from unittest.mock import patch

from playwright.sync_api import sync_playwright, expect

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from tools import course, course_web


def check():
    original_progress = course.PROGRESS_FILE.read_bytes()
    original_source = (ROOT / 'workspaces/09/09_01/main.cpp').read_bytes()
    solution = (course.SOLUTIONS / '09_01/main.cpp').read_text()
    with tempfile.TemporaryDirectory(dir='/tmp/opencode') as directory:
        root = Path(directory)
        workspace = root / 'workspaces'
        for lesson in course_web.chapter_lessons():
            shutil.copytree(course.STARTERS / lesson['key'], workspace / '09' / lesson['key'])
        test_runs = []

        def runner(lesson_id):
            test_runs.append(lesson_id)
            step = course_web.practice_activity(lesson_id)
            if step is not None:
                return course_web.run_practice_tests(step)
            lesson = course.lesson_by_id(lesson_id)
            passed, message = course.compile_and_run(lesson, course.workspace_path(lesson))
            return {'passed': passed, 'message': message}

        progress = root / 'progress.json'
        progress.write_text(json.dumps({'completed': ['09_02'], 'hintsViewed': {}}))
        fixture_progress = progress.read_bytes()
        steps = course_web.activities()
        final = next(step for step in steps if step['id'] == '9.1-code')
        other = next(step for step in steps if step['kind'] != 'code' and step['lessonId'] != final['lessonId'])
        practice = next(step for step in steps if step.get('practice') and sum(
            bool(item.get('practice')) for item in steps if item['lessonId'] == step['lessonId']) > 1)
        sibling = next(step for step in steps if step.get('practice') and
                       step['lessonId'] == practice['lessonId'] and step['id'] != practice['id'])
        parent = next(step for step in steps if step['lessonId'] == practice['lessonId'] and
                      step['kind'] == 'code' and not step.get('practice'))
        with patch.object(course, 'ROOT', root), patch.object(course, 'WORKSPACES', workspace), \
                patch.object(course, 'BUILD', root / 'build'), \
                patch.object(course, 'PROGRESS_FILE', progress), patch.object(course, 'STATE', root):
            # Trusted test drivers must remain located in the real repository.
            real_compile = course.compile_and_run

            def compile_fixture(lesson, source_dir):
                fixture_lesson = {**lesson, 'behaviorTests': [str(ROOT / driver) for driver in lesson['behaviorTests']]}
                return real_compile(fixture_lesson, source_dir)

            with patch.object(course, 'compile_and_run', side_effect=compile_fixture):
                server = course_web.CourseServer(('127.0.0.1', 0), runner=runner)
                thread = threading.Thread(target=server.serve_forever, daemon=True)
                thread.start()
                try:
                    with sync_playwright() as playwright:
                        browser = playwright.chromium.launch(headless=True, executable_path=shutil.which('chromium'))
                        page = browser.new_page(viewport={'width': 1600, 'height': 1000})
                        errors = []
                        page.on('pageerror', lambda error: errors.append(str(error)))
                        page.route('https://www.learncpp.com/**', lambda route: route.fulfill(body='<html>Reader fixture</html>'))
                        page.goto(server.origin + '/#9.1-code')
                        expect(page.locator('.CodeMirror')).to_be_visible()
                        expect(page.locator('#activity-title')).to_have_text(final['title'])
                        before_progress = page.locator('#progress-label').inner_text()
                        before_completion = page.request.get(server.origin + '/api/course').json()['lessons']
                        get_source = lambda: page.evaluate("() => document.querySelector('.CodeMirror').CodeMirror.getValue()")
                        focus = lambda: page.evaluate("() => document.querySelector('.CodeMirror').CodeMirror.focus()")
                        path = workspace / '09/09_01/main.cpp'
                        focus()
                        page.keyboard.press('i')
                        expect(page.locator('#editor-mode')).to_have_text('INSERT')
                        page.keyboard.type('// typed locally in Insert mode\n')
                        expect(page.locator('#save-status')).to_have_text('Unsaved changes')
                        typed = get_source()
                        page.keyboard.press('Alt+r')
                        expect(page.locator('#run-status')).to_have_text('NEEDS WORK', timeout=15000)
                        assert path.read_text() == typed
                        assert get_source() == typed  # Alt+R did not insert an r.
                        expect(page.locator('#save-status')).to_have_text('Saved')

                        # Normal-mode editing, undo, and Ex :w use the mature Vim keymap.
                        page.keyboard.press('Escape')
                        expect(page.locator('#editor-mode')).to_have_text('NORMAL')
                        page.keyboard.type('ggx')
                        assert get_source() != typed
                        page.keyboard.press('u')
                        assert get_source() == typed
                        page.keyboard.press('i')
                        page.keyboard.type('// saved using colon-w\n')
                        page.keyboard.press('Escape')
                        page.keyboard.type(':w')
                        page.keyboard.press('Enter')
                        expect(page.locator('#save-status')).to_have_text('Saved')
                        assert path.read_text() == get_source()

                        # Unsaved drafts and cursor/undo state survive ordinary step navigation.
                        focus()
                        page.keyboard.press('i')
                        page.keyboard.type('// keep my unsaved draft\n')
                        page.keyboard.press('Escape')
                        draft = get_source()
                        page.select_option('#step-select', other['id'])
                        expect(page.locator('#activity-title')).to_have_text(other['title'])
                        page.select_option('#step-select', '9.1-code')
                        expect(page.locator('#code-pane')).to_be_visible()
                        assert get_source() == draft
                        expect(page.locator('#save-status')).to_have_text('Unsaved changes')

                        # A genuine passing solution is saved and compiled; repeat keys do not double-run.
                        page.evaluate('(source) => document.querySelector(".CodeMirror").CodeMirror.setValue(source)', solution)
                        focus()
                        before = len(test_runs)
                        page.keyboard.press('Alt+r')
                        page.keyboard.press('Alt+r')
                        expect(page.locator('#run-status')).to_have_text('PASSED', timeout=15000)
                        assert len(test_runs) == before + 1
                        assert path.read_text() == solution
                        expect(page.locator('#save-status')).to_have_text('Saved')

                        # External edits win over a stale browser revision; the draft is retained.
                        path.write_text('// external editor changed this file\n')
                        page.evaluate('() => { const cm = document.querySelector(".CodeMirror").CodeMirror; cm.setValue(cm.getValue() + "\\n// still in my draft\\n"); }')
                        draft = get_source()
                        focus()
                        page.keyboard.press('Alt+r')
                        expect(page.locator('#app-error')).to_contain_text('changed on disk')
                        assert path.read_text() == '// external editor changed this file\n'
                        assert get_source() == draft
                        assert len(test_runs) == before + 1
                        page.once('dialog', lambda dialog: dialog.dismiss())
                        page.locator('#reload').click()
                        assert get_source() == draft
                        page.once('dialog', lambda dialog: dialog.accept())
                        page.locator('#reload').click()
                        expect(page.locator('#save-status')).to_have_text('Saved')
                        assert get_source() == path.read_text()

                        # GET the real activity, not a mocked editor or parent assignment.
                        response = page.request.get(server.origin + '/api/activities/' + practice['id'])
                        assert response.ok, response.text()
                        content = response.json()
                        practice_path = root / content['path']
                        assert practice_path.is_relative_to(workspace)
                        assert content['id'] == practice['id']
                        assert content['source'] == practice['practice']['starter']
                        parent_path = course.workspace_path(course.lesson_by_id(parent['lessonId'])) / 'main.cpp'
                        parent_saved = parent_path.read_text()

                        def navigate(step):
                            page.select_option('#step-select', step['id'])
                            expect(page.locator('#activity-title')).to_have_text(step['title'])
                            expect(page.locator('#code-pane')).to_be_visible()

                        set_source = lambda source: page.evaluate(
                            '(source) => document.querySelector(".CodeMirror").CodeMirror.setValue(source)', source)
                        navigate(parent)
                        parent_draft = parent_saved + '\n// unsaved parent final draft\n'
                        set_source(parent_draft)
                        navigate(sibling)
                        sibling_content = page.request.get(server.origin + '/api/activities/' + sibling['id']).json()
                        sibling_path = root / sibling_content['path']
                        sibling_saved = sibling_path.read_text()
                        sibling_draft = sibling_saved + '\n// unsaved sibling practice draft\n'
                        set_source(sibling_draft)

                        navigate(practice)
                        assert get_source() == content['source']
                        expect(page.locator('#activity-kind')).to_have_text('MINI CHALLENGE · PRACTICE ONLY')
                        expect(page.locator('#file-path-label')).to_have_text(content['path'])
                        expect(page.locator('#submit-command')).to_be_hidden()
                        before = len(test_runs)
                        focus()
                        page.keyboard.press('Alt+r')
                        expect(page.locator('#run-status')).to_have_text('NEEDS WORK', timeout=15000)
                        assert test_runs[before:] == [practice['id']]
                        assert practice_path.read_text() == content['source']
                        expect(page.locator('#test-output')).to_contain_text('failed')

                        page.locator('#solution-btn').click()
                        expect(page.locator('#solution-view')).to_have_text(content['solution'])
                        set_source(content['solution'])
                        focus()
                        page.keyboard.press('Alt+r')
                        expect(page.locator('#run-status')).to_have_text('PASSED', timeout=15000)
                        expect(page.locator('#test-output')).to_contain_text('All mini-challenge tests passed')
                        expect(page.locator('#save-status')).to_have_text('Saved')
                        assert test_runs[before:] == [practice['id'], practice['id']]
                        assert practice_path.read_text() == content['solution']
                        saved_content = page.request.get(server.origin + '/api/activities/' + practice['id']).json()
                        assert saved_content['source'] == content['solution']
                        assert saved_content['revision'] != content['revision']
                        assert parent_path.read_text() == parent_saved
                        assert sibling_path.read_text() == sibling_saved

                        # Each activity owns its buffer, dirty flag, and saved revision.
                        practice_draft = content['solution'] + '\n// unsaved mini draft after passing\n'
                        set_source(practice_draft)
                        for step, expected in [(parent, parent_draft), (sibling, sibling_draft),
                                               (practice, practice_draft), (parent, parent_draft)]:
                            navigate(step)
                            assert get_source() == expected, step['id']
                            expect(page.locator('#save-status')).to_have_text('Unsaved changes')
                        assert practice_path.read_text() == content['solution']
                        assert parent_path.read_text() == parent_saved
                        assert sibling_path.read_text() == sibling_saved
                        assert progress.read_bytes() == fixture_progress
                        assert page.locator('#progress-label').inner_text() == before_progress
                        assert page.request.get(server.origin + '/api/course').json()['lessons'] == before_completion
                        assert not errors, errors
                        browser.close()
                finally:
                    server.shutdown()
                    server.server_close()
                    thread.join()
    assert course.PROGRESS_FILE.read_bytes() == original_progress
    assert (ROOT / 'workspaces/09/09_01/main.cpp').read_bytes() == original_source
    print('Browser editor checks passed: Vim modes/undo/:w, Alt+R saves and compiles in both modes, duplicate-run guard, external conflicts, safe reload, real mini-practice starter failure/solution pass, independent parent/sibling/activity drafts; completion and real learner work unchanged.')


if __name__ == '__main__':
    check()
