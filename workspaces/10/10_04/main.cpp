/*
Lesson 10.4 - Narrowing conversions, list initialization, and constexpr initializers
LearnCpp: https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/

Problem:
Implement clampChannel(value), returning an unsigned char in [0,255]. Negative inputs become 0,
inputs above 255 become 255, and in-range values are preserved. Do not allow wraparound. This
challenge uses runtime range validation followed by an explicit narrowing conversion.

Expected results (examples):
- clampChannel(-1) -> 0
- clampChannel(256) -> 255
- clampChannel(128) -> 128

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.4
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_04
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




unsigned char clampChannel(int value)
{
    // TODO: Implement the contract above.
    (void)value; return 0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int value : {-1000,-1,0,1,127,128,254,255,256,1000})
        Lab::eq(static_cast<int>(clampChannel(value)), value < 0 ? 0 : value > 255 ? 255 : value, "channel=" + std::to_string(value));
    return Lab::finish();
}
#endif
