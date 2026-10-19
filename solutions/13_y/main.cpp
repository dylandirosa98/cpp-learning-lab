/*
Lesson 13.y - Using a language reference
LearnCpp: https://www.learncpp.com/cpp-tutorial/using-a-language-reference/

Problem:
Use the standard-library reference linked in lesson.md to implement
boundedTemperature(reading,low,high). If low > high, swap the bounds first. Then return reading
clamped to the inclusive interval. Practice finding std::clamp requirements, return type, and
header rather than copying an unrelated example. All values are ints.

Expected results (examples):
- boundedTemperature(20,0,10) -> 10
- boundedTemperature(-3,10,0) -> 0
- boundedTemperature(5,0,10) -> 5

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.y
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_y
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <utility>



int boundedTemperature(int reading, int low, int high)
{
    if(low>high) std::swap(low,high);
    return std::clamp(reading,low,high);
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for(int reading : {-20,0,5,10,20}) for(int low : {-5,0,10}) for(int high : {-5,0,10}) {
        const int lo{low<high?low:high},hi{low<high?high:low};
        Lab::eq(boundedTemperature(reading,low,high),reading<lo?lo:reading>hi?hi:reading,"normalized clamping bounds");
    }
    return Lab::finish();
}
#endif
