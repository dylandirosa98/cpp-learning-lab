/*
Lesson 10.9 - Type deduction for functions
LearnCpp: https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/

Problem:
Implement auto absoluteGap(left, right), returning the nonnegative integer distance between two
integers. Every return path must deduce the same type, int. Inputs lie between -1000000 and
1000000. Keep the definition before callers so its return type can be deduced.

Expected results (examples):
- absoluteGap(3,8) -> 5
- absoluteGap(8,3) -> 5
- absoluteGap(-4,2) -> 6

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.9
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_09
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>



auto absoluteGap(int left, int right)
{
    if (left < right) return right-left;
    return left-right;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    static_assert(std::is_same_v<decltype(absoluteGap(1,2)), int>);
    for (int left : {-1000000,-4,0,3,8}) for (int right : {-4,0,3,8,1000000})
        Lab::eq(absoluteGap(left,right), left < right ? right-left : left-right, "symmetric integer distance");
    return Lab::finish();
}
#endif
