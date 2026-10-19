/*
Lesson 11.x - Chapter 11 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/

Problem:
Implement clampValue<T>(value, low, high) and discounted<Percent,T>(price). clampValue returns
low below the lower bound, high above the upper bound, or value inside; low <= high is
guaranteed. discounted returns price*(100-Percent)/100.0 as double, preserving fractions.
Percent is a compile-time integer in [0,100]; prices are finite and nonnegative. Both templates
must work with int and double inputs.

Expected results (examples):
- clampValue(12,0,10) -> 10
- clampValue(0.25,0.0,1.0) -> 0.25
- discounted<25>(10) -> 7.5

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.x
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_x
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>




template <typename T>
T clampValue(T value, T low, T high)
{
    // TODO: Implement the contract above.
    (void)low; (void)high; return value;
}

template <int Percent, typename T>
double discounted(T price)
{
    // TODO: Implement the contract above.
    (void)price; return 0.0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(clampValue(-1,0,10),0,"below lower bound"); Lab::eq(clampValue(12,0,10),10,"above upper bound");
    Lab::eq(clampValue(5,0,10),5,"inside interval"); Lab::eq(clampValue(5,3,3),3,"single-value interval");
    Lab::near(clampValue(0.25,0.0,1.0),0.25,"double interval"); Lab::near(clampValue(2.0,0.0,1.0),1.0,"double clamp");
    Lab::near(discounted<25>(10),7.5,"integer price keeps fraction");
    Lab::near(discounted<0>(1.25),1.25,"no discount"); Lab::near(discounted<100>(25),0.0,"full discount");
    Lab::near(discounted<10>(9.99),8.991,"floating price");
    return Lab::finish();
}
#endif
