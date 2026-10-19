/*
Lesson 11.7 - Function template instantiation
LearnCpp: https://www.learncpp.com/cpp-tutorial/function-template-instantiation/

Problem:
Implement squared<T>(value) by returning value*value as T. Support explicit and deduced
instantiations for int, long long, and double. Tested values and products fit their types. Do
not store the result in a fixed int intermediate.

Expected results (examples):
- squared(5) -> 25
- squared<double>(1.5) -> 2.25
- squared<long long>(100000) -> 10000000000

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.7
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_07
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




template <typename T>
T squared(T value)
{
    // TODO: Implement the contract above.
    (void)value; return T{};
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(squared(5),25,"deduced int instance"); Lab::eq(squared<int>(-4),16,"explicit int instance");
    Lab::near(squared<double>(1.5),2.25,"explicit double instance");
    Lab::eq(squared<long long>(100000),10000000000LL,"wide instance must stay wide");
    Lab::eq(squared(0),0,"zero");
    return Lab::finish();
}
#endif
