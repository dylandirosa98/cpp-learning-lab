/*
Lesson 10.6 - Explicit type conversion (casting) and static_cast
LearnCpp: https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/

Problem:
Implement successRate(successes, attempts) as a percentage in [0,100]. Return -1.0 when
attempts <= 0, successes < 0, or successes > attempts. Preserve fractional percentages. Counts
are at most 100000.

Expected results (examples):
- successRate(1,4) -> 25.0
- successRate(1,8) -> 12.5
- successRate(0,0) -> -1.0

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.6
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_06
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




double successRate(int successes, int attempts)
{
    if (attempts <= 0 || successes < 0 || successes > attempts) return -1.0;
    return static_cast<double>(successes) / attempts * 100.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::near(successRate(1,4),25.0,"1 of 4"); Lab::near(successRate(1,8),12.5,"1 of 8");
    Lab::near(successRate(0,5),0.0,"none succeeded"); Lab::near(successRate(5,5),100.0,"all succeeded");
    for (int attempts : {-1,0,1,7}) for (int successes : {-1,0,1,8}) {
        const double expected{attempts <= 0 || successes < 0 || successes > attempts ? -1.0 : static_cast<double>(successes) / attempts * 100.0};
        Lab::near(successRate(successes,attempts),expected,"validated percentage");
    }
    return Lab::finish();
}
#endif
