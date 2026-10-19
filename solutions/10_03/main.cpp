/*
Lesson 10.3 - Numeric conversions
LearnCpp: https://www.learncpp.com/cpp-tutorial/numeric-conversions/

Problem:
Implement wholeDegrees(temperature). Clamp a finite double to [-100,100], then return its
integer part truncated toward zero. Tested values are finite and between -10000 and 10000.
Clamp before converting so the target integer conversion is always in range.

Expected results (examples):
- wholeDegrees(9.9) -> 9
- wholeDegrees(-9.9) -> -9
- wholeDegrees(120.5) -> 100

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.3
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_03
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int wholeDegrees(double temperature)
{
    if (temperature > 100.0) return 100;
    if (temperature < -100.0) return -100;
    return static_cast<int>(temperature);
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (double value : {-10000.0,-100.1,-100.0,-9.9,-0.9,0.0,0.9,9.9,100.0,100.1,10000.0}) {
        const int expected{value < -100 ? -100 : value > 100 ? 100 : static_cast<int>(value)};
        Lab::eq(wholeDegrees(value), expected, "wholeDegrees(" + std::to_string(value) + ")");
    }
    return Lab::finish();
}
#endif
