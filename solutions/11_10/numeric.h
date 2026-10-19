/*
Lesson 11.10 - Using function templates in multiple files
LearnCpp: https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/

Problem:
Implement minOf<T>(left,right) in numeric.h, returning the smaller value (first on equality).
Keep the full template definition visible in the header. main.cpp and the supplied probe.cpp
both instantiate it; Alt+R through the provided CMake target builds both files. Do not edit the
probe or put an int-only replacement in main.cpp.

Expected results (examples):
- minOf(3,8) -> 3
- minOf(1.5,1.25) -> 1.25
- minimumFromOtherFile(8,3) -> 3

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.10
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_10
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#ifndef LAB_NUMERIC_H
#define LAB_NUMERIC_H
template <typename T>
T minOf(T left, T right) { return right < left ? right : left; }
#endif
