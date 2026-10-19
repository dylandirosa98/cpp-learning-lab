/*
Lesson 13.4 - Converting an enumeration to and from a string
LearnCpp: https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/

Problem:
Implement colorName(color) and parseColor(text). Names are exactly lowercase "red", "green",
"blue". parseColor returns an engaged optional<Color> for those names, otherwise nullopt; no
whitespace trimming or case folding. colorName receives valid enumerators only. Returning
string_view literals is safe because their storage lasts for the program.

Expected results (examples):
- colorName(green) -> "green"
- parseColor("blue") -> blue
- parseColor("Blue") -> nullopt

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.4
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_04
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <optional>

enum Color { red, green, blue };

std::string_view colorName(Color color)
{
    switch(color) { case red: return "red"; case green: return "green"; case blue: return "blue"; }
    return "unknown";
}

std::optional<Color> parseColor(std::string_view text)
{
    if(text=="red") return red;
    if(text=="green") return green;
    if(text=="blue") return blue;
    return std::nullopt;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(colorName(red),std::string_view{"red"},"red label"); Lab::eq(colorName(green),std::string_view{"green"},"green label");
    Lab::eq(colorName(blue),std::string_view{"blue"},"blue label");
    Lab::eq(parseColor("red").value_or(blue),red,"parse red"); Lab::eq(parseColor("green").value_or(red),green,"parse green");
    Lab::eq(parseColor("blue").value_or(red),blue,"parse blue");
    for(std::string_view text : {"","Blue"," red","yellow"}) Lab::expect(!parseColor(text).has_value(),"reject unknown name");
    return Lab::finish();
}
#endif
