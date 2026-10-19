/*
Lesson 12.9 - Pointers and const
LearnCpp: https://www.learncpp.com/cpp-tutorial/pointers-and-const/

Problem:
Implement copyIfPresent(source,destination). If either pointer is null, return false without
changing any object. Otherwise copy the source integer into the destination and return true.
source is a pointer to const: do not mutate it. Passing the same object as source and
destination is valid.

Expected results (examples):
- source=4,destination=9 -> destination=4, true
- null source -> false, destination unchanged

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.9
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_09
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




bool copyIfPresent(const int* source, int* destination)
{
    // TODO: Implement the contract above.
    (void)source; (void)destination; return false;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    const int source{4}; int target{9}; Lab::expect(copyIfPresent(&source,&target),"valid copy"); Lab::eq(target,4,"destination changed");
    Lab::expect(!copyIfPresent(nullptr,&target),"null source"); Lab::eq(target,4,"failed copy preserves destination");
    Lab::expect(!copyIfPresent(&source,nullptr),"null destination"); Lab::expect(!copyIfPresent(nullptr,nullptr),"both null");
    Lab::expect(copyIfPresent(&target,&target),"same object copy"); Lab::eq(target,4,"self-copy unchanged");
    return Lab::finish();
}
#endif
