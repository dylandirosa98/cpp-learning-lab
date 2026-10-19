/*
Lesson 10.2 - Floating-point and integral promotion
LearnCpp: https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion/

Problem:
Implement addSmall(signed char left, short right), returning their sum as int. Inputs use left
in [-100,100] and right in [-30000,30000]. Do not store the result in either small input type.
Integral promotion lets the arithmetic use int without losing the sum.

Expected results (examples):
- addSmall(100,30000) -> 30100
- addSmall(-100,-30000) -> -30100
- addSmall(-10,20) -> 10

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.2
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_02
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int addSmall(signed char left, short right)
{
    return left + right;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int left : {-100,-1,0,1,100}) for (int right : {-30000,-20,0,20,30000})
        Lab::eq(addSmall(static_cast<signed char>(left), static_cast<short>(right)), left+right, "promoted addition");
    return Lab::finish();
}
#endif
