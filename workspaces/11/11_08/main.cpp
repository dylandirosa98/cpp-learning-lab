/*
Lesson 11.8 - Function templates with multiple template types
LearnCpp: https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/

Problem:
Implement sumAsDouble<T,U>(left,right), returning the mathematical sum as double. Convert each
operand to double BEFORE adding so mixed signed/unsigned inputs do not wrap. Tested values are
small integers or finite doubles and are exactly representable or checked within 1e-9.

Expected results (examples):
- sumAsDouble(-3,2u) -> -1.0
- sumAsDouble(2,0.5) -> 2.5
- sumAsDouble(1.25,2) -> 3.25

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.8
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_08
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




template <typename T, typename U>
double sumAsDouble(T left, U right)
{
    // TODO: Implement the contract above.
    (void)left; (void)right; return 0.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::near(sumAsDouble(-3,2u),-1.0,"mixed signed and unsigned");
    Lab::near(sumAsDouble(2,0.5),2.5,"integer and double");
    Lab::near(sumAsDouble(1.25,2),3.25,"double and integer");
    Lab::near(sumAsDouble(0u,-2),-2.0,"reverse signedness");
    Lab::near(sumAsDouble(2u,3u),5.0,"same unsigned type");
    return Lab::finish();
}
#endif
