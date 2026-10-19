/*
Lesson 13.2 - Unscoped enumerations
LearnCpp: https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/

Problem:
Implement turnRight(direction) for the supplied unscoped Direction enum. Rotate north -> east
-> south -> west -> north. Inputs are always one of those four enumerators. Prefer a switch
with named cases rather than relying on undocumented integer codes.

Expected results (examples):
- turnRight(north) -> east
- turnRight(west) -> north

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.2
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_02
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


enum Direction { north, east, south, west };

Direction turnRight(Direction direction)
{
    // TODO: Implement the contract above.
    (void)direction; return north;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(turnRight(north),east,"north turns east"); Lab::eq(turnRight(east),south,"east turns south");
    Lab::eq(turnRight(south),west,"south turns west"); Lab::eq(turnRight(west),north,"west wraps north");
    Direction d{north}; for(int i{0};i<4;++i) d=turnRight(d); Lab::eq(d,north,"four turns complete a circle");
    return Lab::finish();
}
#endif
