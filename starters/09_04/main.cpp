/*
Lesson 9.4 - Detecting and handling errors
LearnCpp: https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/

Problem:
Implement safeRemainder(value, divisor). For value >= 0 and divisor > 0, return value %
divisor. Otherwise return -1 without performing remainder. The sentinel is unambiguous because
successful remainders are nonnegative. Do not halt the process or print an error.

Expected results (examples):
- safeRemainder(17,5) -> 2
- safeRemainder(0,5) -> 0
- safeRemainder(4,0) -> -1
- safeRemainder(-4,3) -> -1

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 9.4
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_09_04
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int safeRemainder(int value, int divisor)
{
    // TODO: Implement the contract above.
    (void)value; (void)divisor; return 0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int value{-2}; value <= 30; ++value)
        for (int divisor{-2}; divisor <= 9; ++divisor)
            Lab::eq(safeRemainder(value, divisor), value < 0 || divisor <= 0 ? -1 : value % divisor,
                "value=" + std::to_string(value) + ", divisor=" + std::to_string(divisor));
    return Lab::finish();
}
#endif
