/*
Lesson 13.13 - Class templates
LearnCpp: https://www.learncpp.com/cpp-tutorial/class-templates/

Problem:
Complete the Pair<T> struct with two value-initialized members, T first{} and T second{}, then
implement pairSum(pair), returning their sum as T. The member declarations are intentionally
left for you. Support Pair<int> and Pair<double>; template arguments choose the member types as
well as the function instance.

Expected results (examples):
- Pair<int>{2,3} has sum 5
- Pair<double>{1.25,2.5} has sum 3.75

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.13
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_13
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


template <typename T>
struct Pair {
    // TODO: Declare first and second, both of type T and value-initialized.
};

template <typename T>
T pairSum(const Pair<T>& pair)
{
    // TODO: Implement the contract above.
    (void)pair; return T{};
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Pair<int> integers{2,3}; Lab::eq(pairSum(integers),5,"integer class template");
    Pair<double> fractions{1.25,2.5}; Lab::near(pairSum(fractions),3.75,"double member types");
    Pair<int> empty{}; Lab::eq(empty.first,0,"first value initialization"); Lab::eq(empty.second,0,"second value initialization");
    Lab::eq(pairSum(Pair<int>{-3,1}),-2,"negative pair sum");
    return Lab::finish();
}
#endif
