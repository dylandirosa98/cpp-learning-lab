/*
Lesson 11.3 - Function overload resolution and ambiguous matches
LearnCpp: https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/

Problem:
Implement scale(int) to return twice the input as double, and scale(double) to return 1.5 times
the input. The visible tests also call scale with a char and a float: reason about which
overload is selected by promotion. All values are small and finite.

Expected results (examples):
- scale(4) -> 8.0
- scale(4.0) -> 6.0
- scale(char{4}) -> 8.0
- scale(4.0f) -> 6.0

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.3
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_03
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




double scale(int value)
{
    // TODO: Implement the contract above.
    (void)value; return 0.0;
}

double scale(double value)
{
    // TODO: Implement the contract above.
    (void)value; return 0.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::near(scale(4),8.0,"int exact match"); Lab::near(scale(4.0),6.0,"double exact match");
    Lab::near(scale(char{4}),8.0,"char promotes to int"); Lab::near(scale(4.0f),6.0,"float promotes to double");
    Lab::near(scale(-3),-6.0,"negative integer"); Lab::near(scale(-0.5),-0.75,"negative double");
    return Lab::finish();
}
#endif
