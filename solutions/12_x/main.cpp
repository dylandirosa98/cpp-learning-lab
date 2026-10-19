/*
Lesson 12.x - Chapter 12 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-12-summary-and-quiz/

Problem:
Implement transfer(from,to,amount), returning optional<int> with the new source balance on
success. Both pointers must be non-null and distinct, both balances nonnegative, amount
nonnegative, and source must have enough funds. On any invalid condition return nullopt and
change neither balance. A zero transfer succeeds. Starting balances and amount are at most
10000, so sums fit int. Do not allocate or own the pointed-to accounts.

Expected results (examples):
- from=10,to=3,amount=4 -> from=6,to=7,result=6
- amount greater than balance -> nullopt, unchanged
- same account pointer -> nullopt

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.x
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_x
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <optional>



std::optional<int> transfer(int* from, int* to, int amount)
{
    if (!from || !to || from == to || amount < 0 || *from < 0 || *to < 0 || *from < amount) return std::nullopt;
    *from -= amount;
    *to += amount;
    return *from;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{10},b{3}; auto result{transfer(&a,&b,4)}; Lab::eq(result.value_or(-1),6,"new source balance");
    Lab::eq(a,6,"debit"); Lab::eq(b,7,"credit");
    Lab::expect(!transfer(&a,&b,99).has_value(),"insufficient funds"); Lab::eq(a,6,"failed debit unchanged"); Lab::eq(b,7,"failed credit unchanged");
    Lab::expect(!transfer(&a,&a,1).has_value(),"self transfer rejected");
    Lab::expect(!transfer(nullptr,&b,1).has_value(),"null source"); Lab::expect(!transfer(&a,nullptr,1).has_value(),"null destination");
    Lab::expect(!transfer(&a,&b,-1).has_value(),"negative amount");
    Lab::eq(transfer(&a,&b,0).value_or(-1),6,"zero transfer succeeds");
    Lab::eq(transfer(&a,&b,6).value_or(-1),0,"engaged zero after emptying source"); Lab::eq(b,13,"conserved funds");
    int bad{-2}; Lab::expect(!transfer(&bad,&b,0).has_value(),"negative source balance");
    Lab::expect(!transfer(&b,&bad,0).has_value(),"negative destination balance"); Lab::eq(b,13,"invalid account leaves valid balance untouched");
    return Lab::finish();
}
#endif
