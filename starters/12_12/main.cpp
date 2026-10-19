/*
Lesson 12.12 - Return by reference and return by address
LearnCpp: https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/

Problem:
Implement largerRef(first,second), returning an int reference to the larger caller-owned
integer. On a tie return first. Do not return a local copy or a temporary. The caller may
assign through the returned reference; tests check object identity, not just equal values.

Expected results (examples):
- a=3,b=8; largerRef(a,b)=20; -> b=20
- equal values -> reference to first

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.12
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_12
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int& largerRef(int& first, int& second)
{
    // TODO: Implement the contract above.
    (void)second; return first;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{3},b{8}; Lab::expect(&largerRef(a,b)==&b,"return larger object's identity");
    largerRef(a,b)=20; Lab::eq(b,20,"assignment through returned reference"); Lab::eq(a,3,"other object unchanged");
    int c{5},d{5}; Lab::expect(&largerRef(c,d)==&c,"ties choose first identity");
    Lab::expect(&largerRef(a,a)==&a,"same object twice");
    return Lab::finish();
}
#endif
