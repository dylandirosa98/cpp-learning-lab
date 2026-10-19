/*
Lesson 11.9 - Non-type template parameters
LearnCpp: https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/

Problem:
Implement scaleBy<Factor>(value), multiplying an int value by the compile-time integer Factor.
Factor may be positive, zero, or negative. All products fit int. Factor is a template argument,
not a runtime function parameter.

Expected results (examples):
- scaleBy<3>(7) -> 21
- scaleBy<0>(7) -> 0
- scaleBy<-2>(7) -> -14

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.9
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_09
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




template <int Factor>
int scaleBy(int value)
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
    for (int value : {-5,0,7,100}) {
        Lab::eq(scaleBy<3>(value),3*value,"positive template factor");
        Lab::eq(scaleBy<0>(value),0,"zero template factor");
        Lab::eq(scaleBy<-2>(value),-2*value,"negative template factor");
        Lab::eq(scaleBy<1>(value),value,"identity template factor");
    }
    return Lab::finish();
}
#endif
