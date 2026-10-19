/*
Lesson 12.10 - Pass by address
LearnCpp: https://www.learncpp.com/cpp-tutorial/pass-by-address/

Problem:
Implement resetIfPresent(value). A non-null pointer means reset that caller-owned integer to
zero. A null pointer means no action. Do not allocate, delete, or retain the address.

Expected results (examples):
- n=9; resetIfPresent(&n); -> n=0
- resetIfPresent(nullptr) is a safe no-op

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.10
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_10
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




void resetIfPresent(int* value)
{
    // TODO: Implement the contract above.
    (void)value;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int n{9}; resetIfPresent(&n); Lab::eq(n,0,"reset caller");
    n=-8; resetIfPresent(&n); Lab::eq(n,0,"reset negative caller");
    resetIfPresent(nullptr); Lab::expect(true,"null call returned safely");
    return Lab::finish();
}
#endif
