/*
Lesson 9.2 - Code coverage
LearnCpp: https://www.learncpp.com/cpp-tutorial/code-coverage/

Problem:
Implement shippingFee(weight, express). Weight <= 0 is invalid and returns -1, even for
express. Valid weights 1..5 cost 5, weights 6..20 cost 10, and larger weights cost 20. Express
adds 7 only to valid orders. Test both express choices in every weight category and directly on
the 5/6 and 20/21 boundaries.

Expected results (examples):
- shippingFee(5,false) -> 5
- shippingFee(6,true) -> 17
- shippingFee(21,false) -> 20
- shippingFee(0,true) -> -1

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 9.2
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_09_02
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




int shippingFee(int weight, bool express)
{
    if (weight <= 0) return -1;
    const int base{weight <= 5 ? 5 : weight <= 20 ? 10 : 20};
    return base + (express ? 7 : 0);
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (bool express : {false, true}) {
        for (int weight : {-5, 0, 1, 4, 5, 6, 19, 20, 21, 100}) {
            const int expected{weight <= 0 ? -1 : (weight <= 5 ? 5 : weight <= 20 ? 10 : 20) + (express ? 7 : 0)};
            Lab::eq(shippingFee(weight, express), expected, "weight=" + std::to_string(weight) + ", express=" + std::to_string(express));
        }
    }
    return Lab::finish();
}
#endif
