/*
Lesson 5.x - Chapter 5 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-5-summary-and-quiz/
Tasks:
- Declare the presentation functions used by the coordinator.
- Accept names and the heading as cheap read-only std::string_view parameters.
Function responsibilities:
- printHeading and printPerson produce the heading and numbered person lines.
- printOlderPerson, printAgeDifference, and printFirstOlderCheck present results.
- printTieResult states the tie rule and prints the already-selected name.
Expected output from the complete program:
- The report lists Ada Lovelace (age 36), Charles Babbage (age 79), identifies
  Charles as older, prints a 43-year difference, and selects Ada for a tie.
- The reverse check also selects Charles when he is supplied as the first person.
- Labels, punctuation, spaces, ordering, and all eight newlines match exactly.
Constraints:
- Keep this header declaration-only, include-guarded, and free of stream output.
- Do not take text as owning std::string values or import namespace std.
Completion checklist:
- Every read-only text parameter is std::string_view.
- Declarations match report.cpp and all are enclosed by the unique guard.
- The complete C++20 target is warning-clean, uses no stdin, and prints exactly.
Run from project root: ./course check 5.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER5_REPORT_H
#define CPP_LEARNING_LAB_CHAPTER5_REPORT_H

#include <string_view>

void printHeading(std::string_view heading);
void printPerson(int number, std::string_view name, int age);
void printOlderPerson(std::string_view name, int age);
void printAgeDifference(int difference);
void printFirstOlderCheck(std::string_view name);
void printTieResult(std::string_view name);

#endif
