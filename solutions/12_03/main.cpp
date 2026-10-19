/*
Lesson 12.3 - Lvalue references
LearnCpp: https://www.learncpp.com/cpp-tutorial/lvalue-references/

Problem:
Implement addTo(target,delta). target is an int lvalue reference: change the caller's integer
by adding delta. delta may be negative or zero. Inputs and sums fit int. A reference is an
alias to the existing object, not a separate copy to return.

Expected results (examples):
- int n=4; addTo(n,3); -> n is 7
- addTo(n,-2) subtracts two

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.3
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_03
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




void addTo(int& target, int delta)
{
    target += delta;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int value{4}; int& alias{value}; addTo(value,3); Lab::eq(value,7,"modify caller");
    addTo(alias,-2); Lab::eq(value,5,"reference aliases same object");
    addTo(value,0); Lab::eq(value,5,"zero delta");
    return Lab::finish();
}
#endif
