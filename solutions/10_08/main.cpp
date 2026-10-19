/*
Lesson 10.8 - Type deduction for objects using the auto keyword
LearnCpp: https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/

Problem:
Implement midpoint(low, high) returning their floating-point midpoint, even for odd sums or
reversed endpoints. Inputs are between -1000000 and 1000000. Use auto for a local intermediate
so its type follows the expression; the tests care about the double result, not how you spell
locals.

Expected results (examples):
- midpoint(1,4) -> 2.5
- midpoint(4,1) -> 2.5
- midpoint(-4,1) -> -1.5

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.8
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_08
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




double midpoint(int low, int high)
{
    const auto sum{low + high};
    return sum / 2.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int low : {-1000000,-4,0,1,4}) for (int high : {-4,0,1,4,1000000})
        Lab::near(midpoint(low,high),(static_cast<double>(low)+high)/2.0,"midpoint endpoints");
    return Lab::finish();
}
#endif
