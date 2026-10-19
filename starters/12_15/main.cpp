/*
Lesson 12.15 - std::optional
LearnCpp: https://www.learncpp.com/cpp-tutorial/stdoptional/

Problem:
Implement parseDigit(character). For ASCII characters 0..9 return an engaged std::optional<int>
containing the numeric digit. For any other character return std::nullopt. An engaged zero is a
valid result and is different from an empty optional.

Expected results (examples):
- parseDigit('0') -> optional containing 0
- parseDigit('9') -> optional containing 9
- parseDigit('x') -> nullopt

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.15
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_15
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <optional>



std::optional<int> parseDigit(char character)
{
    // TODO: Implement the contract above.
    (void)character; return std::nullopt;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (char c{'0'}; c <= '9'; ++c) {
        const auto digit{parseDigit(c)}; Lab::expect(digit.has_value(),"digit is engaged");
        Lab::eq(digit.value_or(-99),c-'0',"decoded digit");
    }
    for (char c : {'x','/',' ',':','-','A'}) Lab::expect(!parseDigit(c).has_value(),"nondigit has no value");
    return Lab::finish();
}
#endif
