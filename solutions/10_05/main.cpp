/*
Lesson 10.5 - Arithmetic conversions
LearnCpp: https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/

Problem:
Implement fitsInBudget(cost, budget). Negative signed costs are invalid and return false.
Otherwise return whether cost is at most the unsigned budget, including equality. Tested costs
fit int and budgets may include the maximum unsigned int value.

Expected results (examples):
- fitsInBudget(-1,100u) -> false
- fitsInBudget(100,100u) -> true
- fitsInBudget(101,100u) -> false

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 10.5
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_10_05
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <limits>



bool fitsInBudget(int cost, unsigned int budget)
{
    return cost >= 0 && static_cast<unsigned int>(cost) <= budget;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::expect(!fitsInBudget(-1,100u), "negative cost is invalid, not a huge unsigned cost");
    Lab::expect(!fitsInBudget(-1,std::numeric_limits<unsigned int>::max()), "negative cost remains invalid at maximum budget");
    Lab::expect(fitsInBudget(0,0u), "zero fits zero");
    Lab::expect(fitsInBudget(100,100u), "equal endpoint");
    Lab::expect(!fitsInBudget(101,100u), "over budget");
    Lab::expect(fitsInBudget(200,std::numeric_limits<unsigned int>::max()), "large unsigned budget");
    return Lab::finish();
}
#endif
