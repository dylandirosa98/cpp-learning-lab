/*
Lesson 7.x - Chapter 7 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
Tasks:
- Declare one externally linked const starting sample ID.
- Declare the persistent ID generator and both calibration API versions.
- Make calibration V2 the inline default version.
Module responsibilities:
- Survey owns sample identity and calibration calculations, never presentation.
- V1 preserves raw values while V2 applies the current implementation detail.
Expected behavior from the complete program:
- IDs begin at 100; legacy calibration keeps 40; default calibration produces 42.
Constraints:
- Keep this header declaration-only, include-guarded, and free of private state.
- Do not define the external object or use an unnamed namespace in this header.
Completion checklist:
- The external constant is uninitialized here and V2 is explicitly inline.
- Both versions expose the same calibrate(int) interface.
- The complete target builds warning-free and passes ./course check 7.x.
Run from project root: ./course check 7.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER7_SURVEY_H
#define CPP_LEARNING_LAB_CHAPTER7_SURVEY_H

namespace Survey {
// TODO: Declare, but do not define, the shared read-only starting ID.
extern const int g_firstSampleId;

int nextSampleId();

namespace V1 {
int calibrate(int rawReading);
}

// TODO: Make V2 the default API with an inline namespace.
inline namespace V2 {
int calibrate(int rawReading);
}
} // namespace Survey

#endif
