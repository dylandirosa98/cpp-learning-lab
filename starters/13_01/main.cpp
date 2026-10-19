/*
Lesson 13.1 - Introduction to program-defined (user-defined) types
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/

Problem:
The supplied Money struct represents integer cents. Implement addMoney(left,right), returning a
new Money containing the sum. Negative amounts are allowed. Do not mutate either input. Tested
sums fit int. Return the program-defined type, not a plain int.

Expected results (examples):
- addMoney(Money{125},Money{75}).cents -> 200
- adding -50 cents subtracts 50 cents

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.1
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_01
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


struct Money { int cents{}; };

Money addMoney(Money left, Money right)
{
    // TODO: Implement the contract above.
    (void)left; (void)right; return {};
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Money a{125},b{75}; Lab::eq(addMoney(a,b).cents,200,"sum of cents");
    Lab::eq(a.cents,125,"left unchanged"); Lab::eq(b.cents,75,"right unchanged");
    Lab::eq(addMoney(Money{-50},Money{25}).cents,-25,"negative adjustment");
    Lab::eq(addMoney(Money{0},Money{0}).cents,0,"zero money");
    return Lab::finish();
}
#endif
