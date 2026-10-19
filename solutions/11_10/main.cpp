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
#include <iostream>
#include <string>
#include <string_view>


#include "numeric.h"
int minimumFromOtherFile(int left, int right);


// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(minOf(3,8),3,"header int instance"); Lab::near(minOf(1.5,1.25),1.25,"header double instance");
    Lab::eq(minimumFromOtherFile(8,3),3,"template instantiated by second source file");
    Lab::eq(minimumFromOtherFile(-4,-2),-4,"second source negative case");
    Lab::eq(minOf(std::string{"ant"},std::string{"bee"}),std::string{"ant"},"header string instance");
    return Lab::finish();
}
#endif
