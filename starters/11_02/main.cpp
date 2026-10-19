/*
Lesson 11.2 - Function overload differentiation
LearnCpp: https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/

Problem:
Implement sameValue(int,int) and sameValue(std::string_view,std::string_view). Return exact
equality for each pair. Text comparison is case-sensitive and compares contents, not addresses.
Empty text equals empty text. Parameter names and return types are not what distinguish these
overloads.

Expected results (examples):
- sameValue(2,2) -> true
- sameValue("cat","Cat") -> false
- sameValue("","") -> true

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 11.2
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_11_02
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <string_view>



bool sameValue(int left, int right)
{
    // TODO: Implement the contract above.
    (void)left; (void)right; return false;
}

bool sameValue(std::string_view left, std::string_view right)
{
    // TODO: Implement the contract above.
    (void)left; (void)right; return false;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::expect(sameValue(2,2),"equal integers"); Lab::expect(!sameValue(-2,2),"different integers");
    Lab::expect(sameValue(std::string_view{"cat"},std::string_view{"cat"}),"equal contents");
    Lab::expect(!sameValue(std::string_view{"cat"},std::string_view{"Cat"}),"case-sensitive contents");
    Lab::expect(sameValue(std::string_view{},std::string_view{}),"empty contents");
    std::string copied{"cat"}; Lab::expect(sameValue(std::string_view{copied},std::string_view{"cat"}),"different storage, same contents");
    return Lab::finish();
}
#endif
