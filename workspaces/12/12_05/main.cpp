/*
Lesson 12.5 - Pass by lvalue reference
LearnCpp: https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/

Problem:
Implement sortPair(first,second), modifying the caller so first <= second. Swap only when
necessary. If both reference parameters refer to the same integer, leave that integer
unchanged. Values fit int; do not use arithmetic swapping that could overflow.

Expected results (examples):
- a=8,b=3; sortPair(a,b); -> a=3,b=8
- sortPair(a,a) leaves a unchanged

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.5
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_05
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




void sortPair(int& first, int& second)
{
    // TODO: Implement the contract above.
    (void)first; (void)second;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{8}, b{3}; sortPair(a,b); Lab::eq(a,3,"smaller stored first"); Lab::eq(b,8,"larger stored second");
    sortPair(a,b); Lab::eq(a,3,"already sorted first"); Lab::eq(b,8,"already sorted second");
    sortPair(a,a); Lab::eq(a,3,"same object for both arguments");
    int c{-1},d{-9}; sortPair(c,d); Lab::eq(c,-9,"negative smaller"); Lab::eq(d,-1,"negative larger");
    return Lab::finish();
}
#endif
