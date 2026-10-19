/*
Lesson 12.11 - Pass by address (part 2)
LearnCpp: https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/

Problem:
Implement redirect(active,replacement). active is a reference to the caller's pointer variable:
make that pointer store replacement, including nullptr. Do not modify either pointed-to
integer. This differs from changing only a local copy of a pointer.

Expected results (examples):
- active=&a; redirect(active,&b); -> active==&b
- redirect(active,nullptr); -> active==nullptr

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.11
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_11
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




void redirect(int*& active, int* replacement)
{
    active = replacement;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{3},b{8}; int* active{&a}; redirect(active,&b); Lab::expect(active==&b,"caller pointer redirected");
    Lab::eq(a,3,"old pointee unchanged"); Lab::eq(b,8,"new pointee unchanged");
    redirect(active,nullptr); Lab::expect(active==nullptr,"redirect to null");
    redirect(active,&a); Lab::expect(active==&a,"redirect from null");
    return Lab::finish();
}
#endif
