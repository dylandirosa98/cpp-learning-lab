/*
Lesson 10.x - Chapter 10 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/

Problem:
Implement invoiceTotal(unitPrice, quantity, discountPercent) in integer Cents and
currencyUnits(cents) as double major units. Invoice total is
unitPrice*quantity*(100-discountPercent)/100, truncating fractional cents only at the end.
Negative unitPrice/quantity or discount outside [0,100] returns -1; zero quantity is valid.
Inputs are unitPrice <= 1000000 and quantity <= 1000. currencyUnits divides any supplied signed
cents by 100.0.

Expected results (examples):
- invoiceTotal(999,3,10) -> 2697
- invoiceTotal(999,0,10) -> 0
- currencyUnits(125) -> 1.25
- currencyUnits(-50) -> -0.5

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.x
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_x
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


using Cents = long long;

Cents invoiceTotal(Cents unitPrice, int quantity, int discountPercent)
{
    // TODO: Implement the contract above.
    (void)unitPrice; (void)quantity; (void)discountPercent; return 0;
}

double currencyUnits(Cents cents)
{
    // TODO: Implement the contract above.
    (void)cents; return 0.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(invoiceTotal(999,3,10),2697LL,"round once after the full subtotal");
    for (Cents price : {-1LL,0LL,1LL,999LL,1000000LL}) for (int quantity : {-1,0,1,3,1000}) for (int discount : {-1,0,10,100,101}) {
        const Cents expected{price < 0 || quantity < 0 || discount < 0 || discount > 100 ? -1 : price*quantity*(100-discount)/100};
        Lab::eq(invoiceTotal(price,quantity,discount),expected,"validated invoice");
    }
    for (Cents cents : {-125LL,-50LL,0LL,1LL,125LL,999999LL}) Lab::near(currencyUnits(cents),cents/100.0,"currency conversion");
    return Lab::finish();
}
#endif
