/*
Lesson 13.7 - Introduction to structs, members, and member selection
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/

Problem:
Implement area(rectangle) and isSquare(rectangle). A rectangle with either dimension <= 0 is
invalid: its area is 0 and isSquare is false. Otherwise area is width*height and a square has
equal dimensions. Dimensions and products fit int.

Expected results (examples):
- Rectangle{3,4} -> area 12, not square
- Rectangle{3,3} -> area 9, square
- Rectangle{0,0} -> area 0, not square

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.7
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_07
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


struct Rectangle { int width{}; int height{}; };

int area(Rectangle rectangle)
{
    if(rectangle.width<=0 || rectangle.height<=0) return 0;
    return rectangle.width*rectangle.height;
}

bool isSquare(Rectangle rectangle)
{
    return rectangle.width>0 && rectangle.height>0 && rectangle.width==rectangle.height;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for(int width : {-1,0,1,3,4}) for(int height : {-1,0,1,3,4}) {
        Rectangle r{width,height};
        Lab::eq(area(r),width<=0||height<=0?0:width*height,"rectangle area");
        Lab::eq(isSquare(r),width>0&&height>0&&width==height,"valid square classification");
    }
    return Lab::finish();
}
#endif
