/*
Lesson 12.14 - Type deduction with pointers, references, and const
LearnCpp: https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/

Problem:
Implement selectCounter(first,second,chooseFirst), preserving a modifiable lvalue reference in
its deduced return type. chooseFirst selects first when true, otherwise second. The signature
uses auto&; returning a value copy would break assignment through the result.

Expected results (examples):
- selectCounter(a,b,true)=7; -> a=7
- selectCounter(a,b,false)=9; -> b=9

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.14
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_14
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>



auto& selectCounter(int& first, int& second, bool chooseFirst)
{
    return chooseFirst ? first : second;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{1},b{2}; static_assert(std::is_same_v<decltype(selectCounter(a,b,true)),int&>);
    Lab::expect(&selectCounter(a,b,true)==&a,"first reference selected");
    Lab::expect(&selectCounter(a,b,false)==&b,"second reference selected");
    selectCounter(a,b,true)=7; selectCounter(a,b,false)=9; Lab::eq(a,7,"write through first"); Lab::eq(b,9,"write through second");
    return Lab::finish();
}
#endif
