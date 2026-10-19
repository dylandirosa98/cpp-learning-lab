/*
Lesson 13.6 - Scoped enumerations (enum classes)
LearnCpp: https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/

Problem:
Implement canEdit(access, ownsDocument). Admins can edit every document; members can edit only
their own; guests can never edit. Use the scoped Access enumerators rather than treating access
as an integer.

Expected results (examples):
- canEdit(Access::admin,false) -> true
- canEdit(Access::member,false) -> false
- canEdit(Access::member,true) -> true

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.6
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_06
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


enum class Access { guest, member, admin };

bool canEdit(Access access, bool ownsDocument)
{
    return access==Access::admin || (access==Access::member && ownsDocument);
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for(bool owns : {false,true}) {
        Lab::expect(canEdit(Access::admin,owns),"admin can edit regardless of owner");
        Lab::eq(canEdit(Access::member,owns),owns,"member ownership rule");
        Lab::expect(!canEdit(Access::guest,owns),"guest never edits");
    }
    return Lab::finish();
}
#endif
