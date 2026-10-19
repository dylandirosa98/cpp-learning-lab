/*
Lesson 11.1 - Introduction to function overloading
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/

Problem:
Implement both doubleValue overloads: int -> int and double -> double. Each returns twice its
argument, preserving the appropriate result type. Integer inputs are at most one million in
magnitude. Do not convert the double overload through int.

Expected results (examples):
- doubleValue(3) -> 6
- doubleValue(1.25) -> 2.5
- doubleValue(-2) -> -4

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.1
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_01
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>



int doubleValue(int value)
{
    // TODO: Implement the contract above.
    (void)value; return 0;
}

double doubleValue(double value)
{
    // TODO: Implement the contract above.
    (void)value; return 0.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    static_assert(std::is_same_v<decltype(doubleValue(1)),int>);
    static_assert(std::is_same_v<decltype(doubleValue(1.0)),double>);
    for (int value : {-100,-1,0,1,12345}) Lab::eq(doubleValue(value),value*2,"integer overload");
    for (double value : {-2.5,-0.25,0.0,1.25,100.1}) Lab::near(doubleValue(value),value*2,"double overload");
    return Lab::finish();
}
#endif
