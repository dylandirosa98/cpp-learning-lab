/*
Lesson 11.5 - Default arguments
LearnCpp: https://www.learncpp.com/cpp-tutorial/default-arguments/

Problem:
Implement shippingCost(distance, packages, rate). Return distance*packages*rate, or -1 if
distance < 0, packages < 1, or rate < 0. Add defaults so packages is 1 and rate is 2 when
omitted. The stub deliberately has no defaults yet: adding the defaults is part of the
exercise. All tested products fit int.

Expected results (examples):
- shippingCost(5) -> 10
- shippingCost(5,3) -> 30
- shippingCost(5,3,4) -> 60
- shippingCost(5,0) -> -1

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.5
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_05
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int shippingCost(int distance, int packages, int rate)
{
    // TODO: Implement the contract above.
    (void)distance; (void)packages; (void)rate; return 0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(shippingCost(5),10,"both defaults"); Lab::eq(shippingCost(5,3),30,"rate default only");
    Lab::eq(shippingCost(5,3,4),60,"no defaults"); Lab::eq(shippingCost(0),0,"zero distance");
    Lab::eq(shippingCost(-1),-1,"negative distance"); Lab::eq(shippingCost(5,0),-1,"no packages");
    Lab::eq(shippingCost(5,1,-1),-1,"negative rate"); Lab::eq(shippingCost(5,2,0),0,"free rate");
    return Lab::finish();
}
#endif
