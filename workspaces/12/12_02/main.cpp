/*
Lesson 12.2 - Value categories (lvalues and rvalues)
LearnCpp: https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/

Problem:
Implement nextTicket(current), returning the next integer ticket after current without changing
the caller. Inputs are between -1000000 and 1000000. Practice incrementing the named local
parameter, and compare calls using a named variable, a literal, and an expression. Each caller
supplies a value; the parameter itself is a named lvalue inside the function.

Expected results (examples):
- nextTicket(4) -> 5
- nextTicket(2+3) -> 6
- calling nextTicket(ticket) leaves ticket unchanged

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.2
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_02
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int nextTicket(int current)
{
    // TODO: Implement the contract above.
    (void)current; return 0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int ticket{4}; Lab::eq(nextTicket(ticket),5,"named lvalue argument");
    Lab::eq(ticket,4,"value parameter does not mutate caller");
    Lab::eq(nextTicket(4),5,"literal rvalue argument"); Lab::eq(nextTicket(2+3),6,"expression rvalue argument");
    Lab::eq(nextTicket(-1),0,"negative ticket");
    return Lab::finish();
}
#endif
