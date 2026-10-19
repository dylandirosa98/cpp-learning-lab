/*
Lesson 12.1 - Introduction to compound data types
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-compound-data-types/

Problem:
Implement appendTag(name,tag), returning an owned std::string containing name + "[" + tag +
"]". name is passed by value, so editing the local copy must not change the caller. Empty names
and tags are valid. This builds on the string class type you already know while introducing the
idea of compound types.

Expected results (examples):
- appendTag("Ada","cpp") -> "Ada[cpp]"
- appendTag("","") -> "[]"

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 12.1
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_12_01
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <string_view>



std::string appendTag(std::string name, std::string_view tag)
{
    // TODO: Implement the contract above.
    (void)tag; return name;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    std::string name{"Ada"}; Lab::eq(appendTag(name,"cpp"),std::string{"Ada[cpp]"},"tagged copy");
    Lab::eq(name,std::string{"Ada"},"caller remains unchanged");
    Lab::eq(appendTag("",""),std::string{"[]"},"empty fields");
    Lab::eq(appendTag("two words","x y"),std::string{"two words[x y]"},"preserve spaces");
    return Lab::finish();
}
#endif
