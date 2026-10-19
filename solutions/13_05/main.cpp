/*
Lesson 13.5 - Introduction to overloading the I/O operators
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-overloading-the-i-o-operators/

Problem:
Implement operator<< and operator>> for Color. Output exactly the lowercase color name with no
newline. Input extracts one whitespace-delimited word; recognized names update color, unknown
words set failbit and leave color unchanged. Failed extraction also leaves color unchanged.
Return the original stream reference from both operators so chaining works. Unlike most
challenges, text format is the actual API being exercised here.

Expected results (examples):
- out << red << " " << blue -> "red blue"
- input "green" -> green and success
- input "purple" -> failbit, old value preserved

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.5
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_05
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <sstream>

enum Color { red, green, blue };

std::ostream& operator<<(std::ostream& out, Color color)
{
    switch(color) { case red: out<<"red"; break; case green: out<<"green"; break; case blue: out<<"blue"; break; }
    return out;
}

std::istream& operator>>(std::istream& in, Color& color)
{
    std::string text;
    if(!(in>>text)) return in;
    if(text=="red") color=red;
    else if(text=="green") color=green;
    else if(text=="blue") color=blue;
    else in.setstate(std::ios::failbit);
    return in;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    std::ostringstream output; Lab::expect(&(output<<red)==&output,"output returns same stream");
    output<<" "<<green<<" "<<blue; Lab::eq(output.str(),std::string{"red green blue"},"chain formatted colors");
    std::istringstream input{"green blue"}; Color first{red},second{red};
    Lab::expect(&(input>>first)==&input,"input returns same stream"); input>>second;
    Lab::expect(!input.fail(),"known colors parse"); Lab::eq(first,green,"first token"); Lab::eq(second,blue,"second token");
    std::istringstream bad{"purple"}; Color old{green}; bad>>old; Lab::expect(bad.fail(),"unknown color sets failbit"); Lab::eq(old,green,"unknown token preserves object");
    std::istringstream empty{""}; empty>>old; Lab::expect(empty.fail(),"empty extraction fails"); Lab::eq(old,green,"EOF preserves object");
    return Lab::finish();
}
#endif
