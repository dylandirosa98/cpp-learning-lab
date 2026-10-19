/*
Lesson 11.6 - Function templates
LearnCpp: https://www.learncpp.com/cpp-tutorial/function-templates/

Problem:
Implement maxOf<T>(left,right), returning the larger value, or the first value when equal. The
provided template parameter T lets the same body work for int, double, and std::string. Return
T, not int, so text and fractional values survive.

Expected results (examples):
- maxOf(3,8) -> 8
- maxOf(1.5,1.25) -> 1.5
- maxOf(string("ant"),string("bee")) -> "bee"

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.6
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_06
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




template <typename T>
T maxOf(T left, T right)
{
    return left < right ? right : left;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(maxOf(3,8),8,"int maximum"); Lab::eq(maxOf(8,3),8,"reversed maximum");
    Lab::eq(maxOf(-4,-2),-2,"negative maximum"); Lab::eq(maxOf(7,7),7,"equal values");
    Lab::near(maxOf(1.5,1.25),1.5,"double maximum");
    Lab::eq(maxOf(std::string{"ant"},std::string{"bee"}),std::string{"bee"},"string maximum");
    return Lab::finish();
}
#endif
