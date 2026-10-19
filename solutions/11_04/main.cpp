/*
Lesson 11.4 - Deleting functions
LearnCpp: https://www.learncpp.com/cpp-tutorial/deleting-functions/

Problem:
Implement wholeUnits(int units): return units when nonnegative, otherwise 0. Also prohibit
calls with a double by declaring the double overload deleted. Add that declaration in the
indicated API area, not an implementation that truncates. The visible compile-time tests verify
that int calls are valid and double calls are not.

Expected results (examples):
- wholeUnits(7) -> 7
- wholeUnits(-1) -> 0
- wholeUnits(2.5) must not be a valid call

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.4
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_04
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


int wholeUnits(double) = delete;

int wholeUnits(int units)
{
    return units < 0 ? 0 : units;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"
template <typename T> concept AcceptsWhole = requires(T value) { wholeUnits(value); };
int main()
{
    static_assert(AcceptsWhole<int>, "int must be accepted");
    static_assert(!AcceptsWhole<double>, "double must be rejected by the API");
    Lab::eq(wholeUnits(7),7,"whole units"); Lab::eq(wholeUnits(0),0,"zero units"); Lab::eq(wholeUnits(-1),0,"negative input");
    return Lab::finish();
}
#endif
