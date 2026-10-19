/*
Lesson 9.6 - Assert and static_assert
LearnCpp: https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/

Problem:
Implement constexpr validPercent(percent), true exactly for [0,100], and
checkedPercent(percent), which asserts that precondition then returns the input. validPercent
must work in constant expressions. checkedPercent must abort on invalid values in a debug
build, not return a sentinel. The provided tests isolate invalid calls in child processes so
Alt+R still reports results. Run these tests with assertions enabled (no NDEBUG, and a Debug
CMake build). Assertions document programmer mistakes; they are not user-input validation.

Expected results (examples):
- validPercent(0) -> true
- validPercent(101) -> false
- checkedPercent(45) -> 45
- checkedPercent(-1) -> assertion abort

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 9.6
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_09_06
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <cassert>



constexpr bool validPercent(int percent)
{
    // TODO: Implement the contract above.
    (void)percent; return false;
}

int checkedPercent(int percent)
{
    // TODO: Implement the contract above.
    (void)percent; return 0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    static_assert(validPercent(0) && validPercent(100));
    static_assert(!validPercent(-1) && !validPercent(101));
    for (int value : {0, 1, 50, 99, 100}) Lab::eq(checkedPercent(value), value, "valid assertion precondition");
    Lab::expectAbort([] { checkedPercent(-1); }, "negative percent must trigger assert");
    Lab::expectAbort([] { checkedPercent(101); }, "percent above 100 must trigger assert");
    return Lab::finish();
}
#endif
