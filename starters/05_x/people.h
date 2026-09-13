/*
Lesson 5.x - Chapter 5 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-5-summary-and-quiz/
Tasks:
- Declare the full-name composition, age-difference, and older-name interfaces.
- Use std::string only for the owned composed result and std::string_view for
  every read-only text parameter and selected non-owning result.
Function responsibilities:
- composeFullName returns a new owning string made from two viewed name parts.
- ageDifference returns the non-negative difference between two ages.
- selectOlderName views one caller-owned name; equal ages select the first.
Expected output from the complete program:
- Age comparison; Ada Lovelace is person 1 at age 36 and Charles Babbage is
  person 2 at age 79; Charles is older by 43 years.
- The final lines state "Tie rule: first person wins" and select Ada Lovelace.
Constraints:
- Keep this header declaration-only and protect it with the unique include guard.
- Do not use streams, namespace imports, definitions, or implementation includes.
Completion checklist:
- Include <string> and <string_view>, and preserve the ownership/view signatures.
- All declarations are inside the guard and match people.cpp exactly.
- The complete C++20 target is warning-clean, uses no stdin, and prints exactly.
Run from project root: ./course check 5.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER5_PEOPLE_H
#define CPP_LEARNING_LAB_CHAPTER5_PEOPLE_H

#include <string>
#include <string_view>

std::string composeFullName(std::string_view firstName, std::string_view lastName);
int ageDifference(int firstAge, int secondAge);
std::string_view selectOlderName(std::string_view firstName, int firstAge, std::string_view secondName, int secondAge);

#endif
