"""Optional UI smoke test: python3 tests/browser_chapter9.py.

Requires Playwright + Chromium. Starts an ephemeral server with disposable
workspaces; never edits, saves, or submits code. External reading is stubbed.
"""

import shutil
import sys
import tempfile
import threading
from pathlib import Path
from unittest.mock import patch

from playwright.sync_api import sync_playwright, expect

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from tools import chapter9_steps, course, course_web


def check(base_url):
    with sync_playwright() as playwright:
        browser = playwright.chromium.launch(headless=True, executable_path=shutil.which('chromium'))
        page = browser.new_page(viewport={'width': 1600, 'height': 1000})
        errors, mutations = [], []
        page.on('pageerror', lambda error: errors.append(str(error)))
        page.on('request', lambda request: mutations.append(request.url) if request.method == 'POST' else None)
        page.route('https://www.learncpp.com/**', lambda route: route.fulfill(
            body='<html><body>External reader fixture</body></html>', content_type='text/html'))
        response = page.request.get(base_url + '/api/course')
        assert response.ok, response.text()
        catalog = response.json()
        steps = catalog['steps']
        assert steps == chapter9_steps.steps_for(course_web.chapter_lessons())
        assert steps
        by_id = {step['id']: step for step in steps}
        page.goto(base_url + '/#' + steps[0]['id'])
        expect(page.locator('#activity-title')).to_have_text(steps[0]['title'])
        before_progress = page.locator('#progress-label').inner_text()
        before_completed = [lesson['completed'] for lesson in catalog['lessons']]
        expect(page.locator('#navigation a')).to_have_count(len(steps))
        expect(page.locator('#step-select option')).to_have_count(len(steps))
        expect(page.locator('#progress')).to_have_attribute('max', str(len(catalog['lessons'])))

        def select(step):
            page.select_option('#step-select', step['id'])
            expect(page.locator('#activity-title')).to_have_text(step['title'])
            expect(page.locator('#activity-objective')).to_have_text(step['objective'])
            expect(page.locator('#step-select')).to_have_value(step['id'])
            expect(page.locator('#navigation [aria-current="page"]')).to_have_attribute('href', '#' + step['id'])

        # Wheel scrolling must reach answers in a long quiz on short desktops.
        # Playwright click auto-scrolling alone can hide clipped-pane bugs.
        long_quiz = max((step for step in steps if step.get('questions')),
                        key=lambda step: len(step['explanation']) + len(step.get('code', '')))
        for width, height in [(1280, 600), (1000, 450)]:
            page.set_viewport_size({'width': width, 'height': height})
            select(long_quiz)
            bounds = page.locator('#quiz-pane').bounding_box()
            assert bounds['y'] + bounds['height'] <= height + 1, 'Quiz extends below the viewport'
            page.locator('#quiz-pane').evaluate('(pane) => { pane.scrollTop = 0; }')
            page.mouse.move(bounds['x'] + bounds['width'] / 2, bounds['y'] + 30)
            page.mouse.wheel(0, 10000)
            expect(page.locator('#quiz-pane')).not_to_have_js_property('scrollTop', 0)
            expect(page.locator('#quiz-options button').last).to_be_in_viewport()
            expect(page.locator('#quiz-to-code')).to_be_in_viewport()
        page.set_viewport_size({'width': 1600, 'height': 1000})

        question_count = 0
        for position, step in enumerate(steps):
            select(step)
            expect(page.locator('#position')).to_have_text(f'{position + 1} of {len(steps)}')
            assert page.locator('#learncpp-frame').get_attribute('src') == next(
                lesson['url'] for lesson in catalog['lessons'] if lesson['id'] == step['lessonId'])
            if step['kind'] == 'read':
                expect(page.locator('#read-pane')).to_be_visible()
                expect(page.locator('#quiz-pane')).to_be_hidden()
                expect(page.locator('#code-pane')).to_be_hidden()
                expect(page.locator('#step-reading')).not_to_be_empty()
            elif step['kind'] == 'code':
                expect(page.locator('#code-pane')).to_be_visible()
                expect(page.locator('#read-pane')).to_be_hidden()
                expect(page.locator('#quiz-pane')).to_be_hidden()
                expect(page.locator('.CodeMirror')).to_be_visible()
                endpoint = '/api/activities/' + step['id'] if step.get('practice') else '/api/lessons/' + step['lessonId']
                response = page.request.get(base_url + endpoint)
                assert response.ok, response.text()
                content = response.json()
                assert page.evaluate('() => document.querySelector(".CodeMirror").CodeMirror.getValue()') == content['source']
                assert page.evaluate('() => document.querySelector(".CodeMirror").CodeMirror.getOption("keyMap")') == 'vim'
                expect(page.locator('#file-path-label')).to_have_text(content['path'])
                expect(page.locator('#save-status')).to_have_text('Saved')
                if step.get('practice'):
                    expect(page.locator('#activity-kind')).to_have_text('MINI CHALLENGE · PRACTICE ONLY')
                    expect(page.locator('#submit-command')).to_be_hidden()
                    expect(page.locator('#practice-hints details')).to_have_count(len(content['hints']))
                else:
                    expect(page.locator('#activity-kind')).to_have_text('CODING ASSIGNMENT')
                    expect(page.locator('#submit-command')).to_have_text('./course check ' + step['lessonId'])
            else:
                expect(page.locator('#quiz-pane')).to_be_visible()
                expect(page.locator('#read-pane')).to_be_hidden()
                expect(page.locator('#code-pane')).to_be_hidden()
                expect(page.locator('#quiz-dots [data-qidx]')).to_have_count(len(step['questions']))
                if step.get('code'):
                    expect(page.locator('#question-code')).to_be_visible()
                    expect(page.locator('#question-code')).to_have_text(step['code'])
                else:
                    expect(page.locator('#question-code')).to_be_hidden()
                for index, question in enumerate(step['questions']):
                    question_count += 1
                    page.locator(f'[data-qidx="{index}"]').click()
                    expect(page.locator('#quiz-question')).to_have_text(question['question'])
                    expect(page.locator('#quiz-options [data-opt]')).to_have_count(len(question['options']))
                    for option, text in enumerate(question['options']):
                        expect(page.locator(f'[data-opt="{option}"]')).to_have_text(text)
                    wrong = (question['answer'] + 1) % len(question['options'])
                    page.locator(f'[data-opt="{wrong}"]').click()
                    expect(page.locator('#quiz-status')).to_have_text('Try again')
                    expect(page.locator('#repair-preview')).to_be_hidden()
                    page.locator(f'[data-opt="{question["answer"]}"]').click()
                    expect(page.locator('#quiz-status')).to_have_text('Correct')
                    expect(page.locator('#quiz-explanation')).to_be_visible()
                    expect(page.locator('#quiz-explanation')).to_have_text(question['explanation'])
                    if step.get('repairTemplate'):
                        expect(page.locator('#repair-preview')).to_be_visible()
                        expect(page.locator('#repair-preview')).to_have_text(
                            step['repairTemplate'].replace('REPLACEMENT', question['options'][question['answer']]))

            # Every pane's Continue follows the authored order, including minis.
            if position + 1 < len(steps):
                button = '#read-continue' if step['kind'] == 'read' else '#code-continue' if step['kind'] == 'code' else '#quiz-to-code'
                page.locator(button).click()
                expect(page.locator('#activity-title')).to_have_text(steps[position + 1]['title'])
                expect(page).to_have_url(base_url + '/#' + steps[position + 1]['id'])

        # Different activities must not share their question-zero answer state.
        first, second = [step for step in steps if len(step.get('questions', [])) == 1][:2]
        select(first)
        question = first['questions'][0]
        wrong = (question['answer'] + 1) % len(question['options'])
        page.locator(f'[data-opt="{wrong}"]').click()
        expect(page.locator('#quiz-status')).to_have_text('Try again')
        select(second)
        expect(page.locator('#quiz-status')).to_have_text('Correct')
        select(first)
        expect(page.locator('#quiz-status')).to_have_text('Try again')
        page.locator(f'[data-opt="{question["answer"]}"]').click()

        # Legacy topic / -quiz / -code bookmarks resolve from the current catalog.
        for lesson in catalog['lessons']:
            topic = [step for step in steps if step['lessonId'] == lesson['id']]
            quiz = next(step for step in topic if step['kind'] in ('quiz', 'predict', 'debug'))
            final = next(step for step in topic if step['kind'] == 'code' and not step.get('practice'))
            for suffix, target in [('', topic[0]), ('-quiz', quiz), ('-code', final)]:
                bookmark = lesson['id'] + suffix
                target = by_id.get(bookmark, target)
                page.goto(base_url + '/#' + bookmark)
                expect(page).to_have_url(base_url + '/#' + target['id'])
                expect(page.locator('#activity-title')).to_have_text(target['title'])

        page.set_viewport_size({'width': 390, 'height': 844})
        for step in steps:
            select(step)
            assert page.evaluate('() => document.documentElement.scrollWidth <= innerWidth'), step['id']
            if step['kind'] == 'code':
                expect(page.locator('.CodeMirror')).to_be_visible()

        assert page.locator('#progress-label').inner_text() == before_progress
        after = page.request.get(base_url + '/api/course').json()
        assert [lesson['completed'] for lesson in after['lessons']] == before_completed
        assert not mutations, mutations
        assert not errors, errors
        browser.close()
        print(f'Browser checks passed: all {len(steps)} steps, {question_count} questions, '
              f'{sum(bool(step.get("practice")) for step in steps)} mini editors, authored navigation, '
              'bookmarks, all steps on mobile; no saves, progress changes, or JS errors.')


def main():
    with tempfile.TemporaryDirectory(dir='/tmp/opencode') as directory:
        root = Path(directory)
        workspace = root / 'workspaces'
        for lesson in course_web.chapter_lessons():
            shutil.copytree(course.STARTERS / lesson['key'], workspace / '09' / lesson['key'])
        progress = root / 'progress.json'
        progress.write_text('{"completed": ["09_02"], "hintsViewed": {}}\n')
        original_progress = progress.read_bytes()
        originals = {path: path.read_bytes() for path in workspace.rglob('*') if path.is_file()}

        def unexpected_run(activity_id):
            raise AssertionError(f'Smoke test must not run code: {activity_id}')

        with patch.object(course, 'ROOT', root), patch.object(course, 'WORKSPACES', workspace), \
                patch.object(course, 'PROGRESS_FILE', progress), patch.object(course, 'STATE', root):
            server = course_web.CourseServer(('127.0.0.1', 0), runner=unexpected_run)
            thread = threading.Thread(target=server.serve_forever, daemon=True)
            thread.start()
            try:
                check(server.origin)
                assert progress.read_bytes() == original_progress
                assert all(path.read_bytes() == source for path, source in originals.items())
                for step in course_web.activities():
                    if step.get('practice'):
                        path = course_web.source_path(course_web.practice_descriptor(step))
                        assert path.read_text() == step['practice']['starter']
            finally:
                server.shutdown()
                server.server_close()
                thread.join()


if __name__ == '__main__':
    main()
