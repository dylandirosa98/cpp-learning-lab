/*
Lesson 13.14 - Class template argument deduction (CTAD) and deduction guides
LearnCpp: https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/

Problem:
Add a deduction guide so Pair{left,right} deduces Pair<std::common_type_t<T,U>> from possibly
mixed numeric arguments. Then implement spanOf(pair), returning the absolute difference of its
two members as T. Pair{2,5.5} must store two doubles, not truncate. std::common_type_t is
provided by <type_traits>; it names the common arithmetic type. Inputs and differences fit
their types.

Expected results (examples):
- Pair{2,5.5} has type Pair<double>
- spanOf(Pair{2,5.5}) -> 3.5
- spanOf(Pair{8,3}) -> 5

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.14
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_14
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

template <typename T>
struct Pair { T first{}; T second{}; };
// TODO: Add the two-argument deduction guide here.

template <typename T>
T spanOf(Pair<T> pair)
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
    const auto mixed{Pair{2,5.5}}; static_assert(std::is_same_v<std::remove_cv_t<decltype(mixed)>,Pair<double>>);
    Lab::near(mixed.first,2.0,"mixed first member"); Lab::near(mixed.second,5.5,"mixed second member");
    Lab::near(spanOf(mixed),3.5,"mixed span"); Lab::eq(spanOf(Pair{8,3}),5,"integer span");
    Lab::eq(spanOf(Pair{3,8}),5,"reversed span"); Lab::near(spanOf(Pair{1.25,1.25}),0.0,"equal double span");
    return Lab::finish();
}
#endif
