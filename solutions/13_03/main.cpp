/*
Lesson 13.3 - Unscoped enumerator integral conversions
LearnCpp: https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/

Problem:
Implement permissionValue(permission), returning its integer code, and
permissionFromCode(code), accepting exactly codes 0/1/2/4 and returning none/readPermission/writePermission/admin
respectively. Unknown codes return none. Do not cast unchecked arbitrary integers into the
enum. The enumerators use explicit nonconsecutive values.

Expected results (examples):
- permissionValue(admin) -> 4
- permissionFromCode(2) -> writePermission
- permissionFromCode(3) -> none

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.3
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_03
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


enum Permission { none=0, readPermission=1, writePermission=2, admin=4 };

int permissionValue(Permission permission)
{
    return static_cast<int>(permission);
}

Permission permissionFromCode(int code)
{
    switch(code) { case 1: return readPermission; case 2: return writePermission; case 4: return admin; default: return none; }
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(permissionValue(none),0,"none code"); Lab::eq(permissionValue(readPermission),1,"read code");
    Lab::eq(permissionValue(writePermission),2,"write code"); Lab::eq(permissionValue(admin),4,"nonconsecutive admin code");
    for(int code{-3};code<=8;++code) Lab::eq(permissionFromCode(code),code==1?readPermission:code==2?writePermission:code==4?admin:none,"validated permission code="+std::to_string(code));
    return Lab::finish();
}
#endif
