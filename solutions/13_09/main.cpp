/*
Lesson 13.9 - Default member initialization
LearnCpp: https://www.learncpp.com/cpp-tutorial/default-member-initialization/

Problem:
Implement configured(retries). Return a Connection using its default timeout=30 and
secure=true. If retries >= 0 override only retries; for negative retries keep its default of 3.
The struct's defaults are already declared and should be used rather than replacing unrelated
fields with zero.

Expected results (examples):
- configured(5) -> timeout 30, retries 5, secure true
- configured(-1) -> timeout 30, retries 3, secure true

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.9
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_09
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


struct Connection { int timeout{30}; int retries{3}; bool secure{true}; };

Connection configured(int retries)
{
    Connection result{};
    if(retries>=0) result.retries=retries;
    return result;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for(int retries : {-5,-1,0,1,5}) {
        const auto c{configured(retries)}; Lab::eq(c.timeout,30,"default timeout preserved");
        Lab::eq(c.retries,retries<0?3:retries,"validated retry override"); Lab::expect(c.secure,"default security preserved");
    }
    return Lab::finish();
}
#endif
