/*
Lesson 9.3 - Common semantic errors in C++
LearnCpp: https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/

Problem:
Implement averageScore(total, count), returning a floating-point average. Return -1.0 if total
< 0 or count <= 0. Inputs are at most 10000. In particular, 5 / 2 must produce 2.5 rather than
2.0. This challenge targets integer division, incorrect guards, and forgotten return paths.

Expected results (examples):
- averageScore(5,2) -> 2.5
- averageScore(0,3) -> 0.0
- averageScore(5,0) -> -1.0

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 9.3
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_09_03
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




double averageScore(int total, int count)
{
    if (total < 0 || count <= 0) return -1.0;
    return static_cast<double>(total) / count;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::near(averageScore(5,2), 2.5, "fractional average, not integer division");
    Lab::near(averageScore(1,4), 0.25, "small fraction");
    Lab::near(averageScore(0,3), 0.0, "zero total is valid");
    Lab::near(averageScore(99,1), 99.0, "one entry");
    Lab::near(averageScore(5,0), -1.0, "zero count");
    Lab::near(averageScore(5,-2), -1.0, "negative count");
    Lab::near(averageScore(-1,2), -1.0, "negative total");
    return Lab::finish();
}
#endif
