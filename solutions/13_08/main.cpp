/*
Lesson 13.8 - Struct aggregate initialization
LearnCpp: https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/

Problem:
Implement translated(point,dx,dy), returning a new Point with x+dx and y+dy. The caller's point
is unchanged. Use aggregate initialization for the returned Point and keep member order in
mind. Coordinates and sums fit int.

Expected results (examples):
- translated(Point{2,3},4,-1) -> Point{6,2}
- zero offsets preserve coordinates

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.8
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_08
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


struct Point { int x{}; int y{}; };

Point translated(Point point, int dx, int dy)
{
    return Point{point.x+dx,point.y+dy};
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Point p{2,3}; const auto moved{translated(p,4,-1)}; Lab::eq(moved.x,6,"translated x"); Lab::eq(moved.y,2,"translated y");
    Lab::eq(p.x,2,"original x unchanged"); Lab::eq(p.y,3,"original y unchanged");
    const auto zero{translated(Point{-5,8},0,0)}; Lab::eq(zero.x,-5,"zero dx"); Lab::eq(zero.y,8,"zero dy");
    const auto origin{translated(Point{2,3},-2,-3)}; Lab::eq(origin.x,0,"translate to origin x"); Lab::eq(origin.y,0,"translate to origin y");
    return Lab::finish();
}
#endif
