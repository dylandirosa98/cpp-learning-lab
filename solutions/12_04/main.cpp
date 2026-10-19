/*
Lesson 12.4 - Lvalue references to const
LearnCpp: https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/

Problem:
Implement maxReadOnly(left,right), returning the larger int by value. The parameters are
references to const, so the function must not alter either argument and must also accept const
objects and temporary integers.

Expected results (examples):
- maxReadOnly(3,8) -> 8
- maxReadOnly(-2,-4) -> -2

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.4
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_04
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int maxReadOnly(const int& left, const int& right)
{
    return left < right ? right : left;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    const int a{3}, b{8}; Lab::eq(maxReadOnly(a,b),8,"const lvalues");
    Lab::eq(a,3,"first input unchanged"); Lab::eq(b,8,"second input unchanged");
    Lab::eq(maxReadOnly(9,2),9,"temporary arguments"); Lab::eq(maxReadOnly(-2,-4),-2,"negative arguments");
    Lab::eq(maxReadOnly(7,7),7,"equal arguments");
    return Lab::finish();
}
#endif
