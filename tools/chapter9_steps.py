"""Independently authored Chapter 9 activities and their source coverage maps."""

import json
from pathlib import Path


CONTENT = Path(__file__).with_name('chapter9')
DOCUMENTS = {item['lessonId']: item for item in
             (json.loads(path.read_text()) for path in sorted(CONTENT.glob('09_*.json')))}
TOPICS = {lesson_id: document['steps'] for lesson_id, document in DOCUMENTS.items()}
# Keep the earlier lesson snapshot API useful to clients browsing quiz questions.
QUIZZES = {
    lesson_id: [(q['question'], q['options'], q['answer'], q['explanation'])
                for step in activities for q in step.get('questions', [])]
    for lesson_id, activities in TOPICS.items()
}


def steps_for(lessons, *, include_practice=False):
    result = []
    for lesson in lessons:
        for activity in TOPICS.get(lesson['id'], []):
            activity = dict(activity)
            suffix = activity.pop('suffix')
            if 'practice' in activity and not include_practice:
                # Source, reference solution, and trusted tests belong to the
                # activity endpoint, not the navigation catalog.
                activity['practice'] = True
            result.append({**activity, 'id': f"{lesson['id']}-{suffix}",
                           'lessonId': lesson['id'],
                           'shortTitle': f"{lesson['id']} {activity['title']}"})
    return result
