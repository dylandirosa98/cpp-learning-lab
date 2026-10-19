/*
Lesson 13.12 - Member selection with pointers and references
LearnCpp: https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/

Problem:
Implement incrementCounter(counter,delta). Return false for nullptr and do nothing. Otherwise
add delta to the pointed-to Counter's value and return true. delta may be negative or zero and
results fit int. Practice the -> operator for pointer member selection.

Expected results (examples):
- Counter{4} incremented by 3 -> value 7, true
- nullptr -> false

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.12
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_12
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


struct Counter { int value{}; };

bool incrementCounter(Counter* counter, int delta)
{
    // TODO: Implement the contract above.
    (void)counter; (void)delta; return false;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Counter c{4}; Lab::expect(incrementCounter(&c,3),"valid counter"); Lab::eq(c.value,7,"pointer member updated");
    Lab::expect(incrementCounter(&c,-2),"negative delta"); Lab::eq(c.value,5,"negative update");
    Lab::expect(incrementCounter(&c,0),"zero delta succeeds"); Lab::expect(!incrementCounter(nullptr,5),"null counter rejected");
    return Lab::finish();
}
#endif
