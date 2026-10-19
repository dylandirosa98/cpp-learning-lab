"""Optional UI smoke test: python3 tests/browser_chapter9.py http://127.0.0.1:8766.

Requires Playwright + Chromium and a running ./course web server. Never edits,
saves, or submits learner code. The external reading frame is stubbed for speed.
"""

import sys

from playwright.sync_api import sync_playwright, expect


def check(base_url):
    with sync_playwright() as playwright:
        browser = playwright.chromium.launch(headless=True)
        page = browser.new_page(viewport={'width': 1600, 'height': 1000})
        errors = []
        page.on('pageerror', lambda error: errors.append(str(error)))
        page.route('https://www.learncpp.com/**', lambda route: route.fulfill(
            body='<html><body>External reader fixture</body></html>', content_type='text/html'))
        page.goto(base_url)
        expect(page.locator('#activity-title')).to_have_text('Compilation is not correctness')
        catalog = page.request.get(base_url + '/api/course').json()
        before_progress = page.locator('#progress-label').inner_text()
        steps = catalog['steps']
        assert len(steps) == 29
        assert page.locator('#navigation a').count() == 29

        for step in steps:
            page.select_option('#step-select', step['id'])
            expect(page.locator('#activity-title')).to_have_text(step['title'])
            expect(page.locator('#activity-objective')).to_have_text(step['objective'])
            assert page.locator('#learncpp-frame').get_attribute('src') == next(
                lesson['url'] for lesson in catalog['lessons'] if lesson['id'] == step['lessonId'])
            if step['kind'] == 'read':
                expect(page.locator('#read-pane')).to_be_visible()
                expect(page.locator('#quiz-pane')).to_be_hidden()
                expect(page.locator('#code-pane')).to_be_hidden()
                expect(page.locator('#step-reading')).to_contain_text(step['explanation'].split('\n')[0])
            elif step['kind'] == 'code':
                expect(page.locator('#code-pane')).to_be_visible()
                expect(page.locator('#read-pane')).to_be_hidden()
                expect(page.locator('#quiz-pane')).to_be_hidden()
            else:
                expect(page.locator('#quiz-pane')).to_be_visible()
                expect(page.locator('#code-pane')).to_be_hidden()
                for index, question in enumerate(step['questions']):
                    page.locator(f'[data-qidx="{index}"]').click()
                    expect(page.locator('#quiz-question')).to_have_text(question['question'])
                    wrong = (question['answer'] + 1) % len(question['options'])
                    page.locator(f'[data-opt="{wrong}"]').click()
                    expect(page.locator('#quiz-status')).to_have_text('Try again')
                    page.locator(f'[data-opt="{question["answer"]}"]').click()
                    expect(page.locator('#quiz-status')).to_have_text('Correct')
                    expect(page.locator('#quiz-explanation')).to_have_text(question['explanation'])
                    if step['kind'] == 'debug':
                        expect(page.locator('#repair-preview')).to_be_visible()
                        expect(page.locator('#repair-preview')).to_have_text(
                            step['repairTemplate'].replace('REPLACEMENT', question['options'][question['answer']]))

        # Reading steps continue through the authored sequence, not straight to code.
        page.select_option('#step-select', '9.5-extraction')
        expect(page.locator('#activity-title')).to_have_text('Successful extraction first')
        page.locator('#read-continue').click()
        expect(page.locator('#activity-title')).to_have_text('Predict a poisoned stream')
        page.locator('#quiz-to-code').click()
        expect(page.locator('#activity-title')).to_have_text('Clear state, then discard the line')

        # Answers on separate single-question steps must not share question 0 state.
        page.select_option('#step-select', '9.5-failure')
        expect(page.locator('#activity-title')).to_have_text('Predict a poisoned stream')
        expect(page.locator('#quiz-status')).to_have_text('Correct')
        page.select_option('#step-select', '9.5-final-token')
        expect(page.locator('#activity-title')).to_have_text('A valid token without a newline')
        expect(page.locator('#quiz-status')).to_have_text('Correct')

        # Bookmark compatibility and topic-entry routing.
        for old_hash, expected in [('#9.3-quiz', '#9.3-division'), ('#9.5', '#9.5-extraction'),
                                   ('#9.1-code', '#9.1-code')]:
            page.goto(base_url + '/' + old_hash)
            expect(page).to_have_url(base_url + '/' + expected)
            expect(page.locator('#activity-title')).not_to_have_text('Loading your next step…')

        # The local editor opens, but this reader smoke test never edits or saves.
        expect(page.locator('.CodeMirror')).to_be_visible()
        assert page.evaluate("() => document.querySelector('.CodeMirror').CodeMirror.getOption('keyMap')") == 'vim'

        page.set_viewport_size({'width': 390, 'height': 844})
        for step_id in ['9.1-idea', '9.3-repair', '9.5-final-token', '9.x-code']:
            page.select_option('#step-select', step_id)
            expected = next(step['title'] for step in steps if step['id'] == step_id)
            expect(page.locator('#activity-title')).to_have_text(expected)
            assert page.evaluate('() => document.documentElement.scrollWidth <= innerWidth'), step_id

        assert page.locator('#progress-label').inner_text() == before_progress
        assert not errors, errors
        browser.close()
        print('Browser checks passed: all 29 steps, five activity types, repairs, navigation, bookmarks, mobile layout; no progress changes or JS errors.')


if __name__ == '__main__':
    check((sys.argv[1] if len(sys.argv) > 1 else 'http://127.0.0.1:8766').rstrip('/'))
