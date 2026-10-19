/*
Lesson 12.8 - Null pointers
LearnCpp: https://www.learncpp.com/cpp-tutorial/null-pointers/

Problem:
Implement valueOr(value,fallback), returning the pointed-to integer when value is non-null,
otherwise fallback. Do not dereference a null pointer. The pointee is read-only through this
pointer.

Expected results (examples):
- valueOr(nullptr,7) -> 7
- n=0; valueOr(&n,7) -> 0

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.8
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_08
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int valueOr(const int* value, int fallback)
{
    return value ? *value : fallback;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(valueOr(nullptr,7),7,"null uses fallback"); int n{0}; Lab::eq(valueOr(&n,7),0,"pointed zero is not null");
    n=-3; Lab::eq(valueOr(&n,7),-3,"pointed negative value"); Lab::eq(n,-3,"pointee unchanged");
    Lab::eq(valueOr(nullptr,-1),-1,"negative fallback");
    return Lab::finish();
}
#endif
