/*
Lesson 12.6 - Pass by const lvalue reference
LearnCpp: https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/

Problem:
Implement longerThan(text,limit), true only when the string length is strictly greater than
limit. The string is passed by const reference; do not copy or mutate it. Empty strings and
limit zero are valid.

Expected results (examples):
- longerThan("cat",2) -> true
- longerThan("cat",3) -> false
- longerThan("",0) -> false

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.6
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_06
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <cstddef>



bool longerThan(const std::string& text, std::size_t limit)
{
    return text.size() > limit;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    const std::string text{"cat"}; Lab::expect(longerThan(text,2),"strictly longer");
    Lab::expect(!longerThan(text,3),"equal length does not qualify"); Lab::expect(!longerThan(text,4),"shorter");
    Lab::expect(!longerThan(std::string{},0),"empty string"); Lab::eq(text,std::string{"cat"},"input unchanged");
    return Lab::finish();
}
#endif
