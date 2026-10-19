/*
Lesson 12.7 - Introduction to pointers
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

Problem:
Implement doublePointed(value), doubling the caller's integer through a pointer. For this
lesson the pointer is guaranteed non-null and the product fits int. Use indirection to access
the pointed-to object rather than modifying the local pointer value.

Expected results (examples):
- n=4; doublePointed(&n); -> n=8
- n=-3 -> n=-6

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.7
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_07
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




void doublePointed(int* value)
{
    *value *= 2;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{4}; doublePointed(&a); Lab::eq(a,8,"pointed positive value");
    int b{-3}; doublePointed(&b); Lab::eq(b,-6,"pointed negative value");
    int c{0}; doublePointed(&c); Lab::eq(c,0,"pointed zero");
    return Lab::finish();
}
#endif
