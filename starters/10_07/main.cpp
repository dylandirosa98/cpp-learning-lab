/*
Lesson 10.7 - Typedefs and type aliases
LearnCpp: https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/

Problem:
The Cents alias names long long. Implement discountedPrice(price, percent): return price times
(100-percent) / 100 in integer cents, discarding any fractional cent. Return -1 for negative
price or percent outside [0,100]. Prices are at most 1000000, so multiplication fits Cents.

Expected results (examples):
- discountedPrice(999,10) -> 899
- discountedPrice(500,100) -> 0
- discountedPrice(-1,10) -> -1

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.7
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_07
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


using Cents = long long;

Cents discountedPrice(Cents price, int percent)
{
    // TODO: Implement the contract above.
    (void)price; (void)percent; return 0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (Cents price : {-1LL,0LL,1LL,999LL,1000000LL}) for (int percent : {-1,0,10,50,100,101})
        Lab::eq(discountedPrice(price,percent), price < 0 || percent < 0 || percent > 100 ? -1LL : price*(100-percent)/100, "discounted integer cents");
    return Lab::finish();
}
#endif
