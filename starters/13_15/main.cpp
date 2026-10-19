/*
Lesson 13.15 - Alias templates
LearnCpp: https://www.learncpp.com/cpp-tutorial/alias-templates/

Problem:
Fix the ScorePair<T> alias so it preserves T instead of always selecting Pair<int>. Then
implement maxScore<T>(pair), returning the larger stored value as T (first on equality). The
alias names an existing specialization; it does not define a new struct. Both integer and
double scores are tested.

Expected results (examples):
- ScorePair<double> must be the same type as Pair<double>
- maxScore<double>({1.25,2.5}) -> 2.5

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.15
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_15
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

template <typename T> struct Pair { T first{}; T second{}; };
template <typename T> using ScorePair = Pair<int>; // TODO: Preserve T.

template <typename T>
T maxScore(const ScorePair<T>& pair)
{
    // TODO: Implement the contract above.
    (void)pair; return T{};
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    static_assert(std::is_same_v<ScorePair<double>,Pair<double>>);
    ScorePair<int> a{2,8}; ScorePair<double> b{1.25,2.5};
    Lab::eq(maxScore<int>(a),8,"aliased integer pair"); Lab::near(maxScore<double>(b),2.5,"aliased double pair");
    Lab::eq(maxScore<int>(ScorePair<int>{-2,-5}),-2,"negative scores"); Lab::near(maxScore<double>(ScorePair<double>{3.5,3.5}),3.5,"equal scores");
    return Lab::finish();
}
#endif
