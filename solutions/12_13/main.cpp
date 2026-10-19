/*
Lesson 12.13 - In and out parameters
LearnCpp: https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/

Problem:
Implement divideWithRemainder(numerator,denominator,quotient,remainder). If denominator is
zero, return false and leave both output integers unchanged. Otherwise write the C++ integer
quotient and remainder, and return true. Output references refer to distinct objects. Inputs
are small, avoiding division overflow.

Expected results (examples):
- 17 / 5 -> quotient=3, remainder=2, true
- -17 / 5 -> quotient=-3, remainder=-2, true
- denominator=0 -> false; outputs unchanged

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.13
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_13
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




bool divideWithRemainder(int numerator, int denominator, int& quotient, int& remainder)
{
    if (denominator == 0) return false;
    quotient = numerator / denominator;
    remainder = numerator % denominator;
    return true;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int n : {-17,-1,0,1,17}) for (int d : {-5,-1,0,1,5}) {
        int q{123},r{456}; const bool ok{divideWithRemainder(n,d,q,r)};
        const std::string input{"numerator=" + std::to_string(n) + ", denominator=" + std::to_string(d)};
        Lab::eq(ok,d!=0,input + ": success status");
        Lab::eq(q,d==0?123:n/d,input + ": quotient or preserved output 123");
        Lab::eq(r,d==0?456:n%d,input + ": remainder or preserved output 456");
    }
    return Lab::finish();
}
#endif
