/*
Lesson 9.1 - Introduction to testing your code
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/

Problem:
Implement isLeapYear(year). A positive year is a leap year when divisible by 400, or divisible
by 4 but not by 100. Nonpositive years return false. Before implementing it, predict each
visible test and add one example of your own. The test suite is executable documentation, not
text you must print.

Expected results (examples):
- isLeapYear(2024) -> true
- isLeapYear(1900) -> false
- isLeapYear(2000) -> true
- isLeapYear(0) -> false

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 9.1
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_09_01
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




bool isLeapYear(int year)
{
    // TODO: Implement the contract above.
    (void)year; return false;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::expect(isLeapYear(2024), "2024 is divisible by 4, not 100");
    Lab::expect(!isLeapYear(2023), "2023 is ordinary");
    Lab::expect(!isLeapYear(1900), "1900 is the century exception");
    Lab::expect(isLeapYear(2000), "2000 is the 400-year exception");
    Lab::expect(!isLeapYear(0), "zero is outside this exercise's domain");
    Lab::expect(!isLeapYear(-400), "negative years are invalid");
    for (int year{1}; year <= 2400; ++year) {
        const bool expected{year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)};
        Lab::eq(isLeapYear(year), expected, "calendar rule for year " + std::to_string(year));
    }
    return Lab::finish();
}
#endif
