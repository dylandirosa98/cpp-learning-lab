/*
Lesson 7.x - Chapter 7 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
Tasks:
- Hide a calibration offset of 2 in an unnamed namespace.
- Define the externally linked first sample ID as 100 exactly once.
- Generate IDs from static local state and implement both API versions.
Module responsibilities:
- nextSampleId owns the unique persistent sequence with block-scoped state.
- V1 returns raw input; V2 adds the source-file-only offset.
Expected behavior from the complete program:
- Three calls return 100, 101, 102; readings become 42, 45, and 40 in V2.
Constraints:
- Include survey.h first and perform no console input or output here.
- Keep the offset internal and the mutable counter local to nextSampleId.
Completion checklist:
- External, internal, and no-linkage names each occupy the intended scope.
- The static counter returns its current value before advancing.
- The complete target builds warning-free and passes ./course check 7.x.
Run from project root: ./course check 7.x
*/
#include "survey.h"

namespace {
constexpr int calibrationOffset{2};
}

namespace Survey {
extern const int g_firstSampleId{100};

int nextSampleId() {
    static int s_nextSampleId{g_firstSampleId};
    return s_nextSampleId++;
}

int V1::calibrate(int rawReading) {
    return rawReading;
}

int V2::calibrate(int rawReading) {
    return rawReading + calibrationOffset;
}
} // namespace Survey
