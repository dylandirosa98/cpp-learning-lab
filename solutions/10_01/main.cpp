/*
Lesson 10.1 - Implicit type conversion
LearnCpp: https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/

Problem:
Implement metersFromCentimeters(cm). Return centimeters divided by 100 as a double, preserving
fractions. Negative distances return -1.0. Test distances are at most one million centimeters.
Think about when conversion happens, not just the return type.

Expected results (examples):
- metersFromCentimeters(125) -> 1.25
- metersFromCentimeters(1) -> 0.01
- metersFromCentimeters(-1) -> -1.0

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.1
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_01
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




double metersFromCentimeters(int cm)
{
    if (cm < 0) return -1.0;
    return cm / 100.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int cm : {-10,-1,0,1,99,100,125,999,1000000})
        Lab::near(metersFromCentimeters(cm), cm < 0 ? -1.0 : cm / 100.0, "centimeters=" + std::to_string(cm));
    return Lab::finish();
}
#endif
