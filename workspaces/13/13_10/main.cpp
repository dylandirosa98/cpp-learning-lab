/*
Lesson 13.10 - Passing and returning structs
LearnCpp: https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/

Problem:
Implement combine(left,right), returning Stats with summed wins and losses without changing
inputs, and winRate(stats), returning wins/(wins+losses) as double. Empty stats have rate 0.0.
Supplied counts are nonnegative and their sums fit int. Rate is a fraction, not a percentage.

Expected results (examples):
- combine(Stats{2,1},Stats{1,3}) -> Stats{3,4}
- winRate(Stats{1,3}) -> 0.25
- winRate(Stats{}) -> 0.0

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.10
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_10
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


struct Stats { int wins{}; int losses{}; };

Stats combine(const Stats& left, const Stats& right)
{
    // TODO: Implement the contract above.
    (void)left; (void)right; return {};
}

double winRate(const Stats& stats)
{
    // TODO: Implement the contract above.
    (void)stats; return 0.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Stats a{2,1},b{1,3}; const auto c{combine(a,b)}; Lab::eq(c.wins,3,"combined wins"); Lab::eq(c.losses,4,"combined losses");
    Lab::eq(a.wins,2,"left unchanged"); Lab::eq(b.losses,3,"right unchanged");
    Lab::near(winRate(Stats{1,3}),0.25,"fractional rate"); Lab::near(winRate(Stats{}),0.0,"empty rate");
    Lab::near(winRate(Stats{3,0}),1.0,"all wins"); Lab::near(winRate(Stats{0,3}),0.0,"all losses");
    return Lab::finish();
}
#endif
