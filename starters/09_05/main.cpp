/*
Lesson 9.5 - std::cin and handling invalid input
LearnCpp: https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/

Problem:
Implement readQuantity() using std::cin. Read an integer at the beginning of each attempted
line; discard the rest of that line. Return the first integer in [1,20]. On invalid text, an
out-of-range number, or integer overflow, discard that line and retry. On end-of-input before a
valid value, return -1. A line beginning "3 extra" is accepted as 3; this is intentionally not
a strict whole-line parser. Do not print prompts. Test scaffolding supplies simulated input
automatically.

Expected results (examples):
- input "hello\n0\n8\n" -> 8
- input "21\n1\n" -> 1
- empty input -> -1
- input "20" with no final newline -> 20

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 9.5
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_09_05
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <limits>
#include <sstream>



int readQuantity()
{
    // TODO: Implement the contract above.
    return 0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    auto readFrom = [](const std::string& input) {
        std::istringstream source{input};
        auto* previous{std::cin.rdbuf(source.rdbuf())};
        std::cin.clear();
        const int result{readQuantity()};
        std::cin.rdbuf(previous);
        std::cin.clear();
        return result;
    };
    Lab::eq(readFrom("hello\n0\n8\n"), 8, "recover from text and range error");
    Lab::eq(readFrom("21\n1\n"), 1, "upper-bound rejection and lower-bound acceptance");
    Lab::eq(readFrom("20"), 20, "valid final token without newline");
    Lab::eq(readFrom("3 extra\n"), 3, "discard trailing text after integer");
    Lab::eq(readFrom("999999999999999999999999\n7\n"), 7, "recover from integer overflow");
    Lab::eq(readFrom(""), -1, "immediate EOF");
    Lab::eq(readFrom("bad\n-3\n"), -1, "EOF after invalid attempts");
    Lab::eq(readFrom("   "), -1, "whitespace-only EOF");
    return Lab::finish();
}
#endif
