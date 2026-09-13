/*
Lesson 5.x - Chapter 5 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-5-summary-and-quiz/
Tasks:
- Print all eight report lines using only values supplied through parameters.
- Keep ownership, name composition, age arithmetic, and person selection elsewhere.
Function responsibilities:
- printHeading prints its supplied literal-backed view.
- printPerson formats "Person N: name (age A)" for either supplied person.
- The remaining functions format the older result, difference, reverse check, and tie.
Expected output from the complete program:
- The first five lines end with Charles Babbage as older at 79 and a difference
  of 43 years; the final two lines document the tie rule and select Ada Lovelace.
- Output is deterministic and exactly eight lines, including exact punctuation.
Constraints:
- Include report.h first; only this module includes iostream or writes output.
- Do not hard-code names, ages, calculated results, or repeat comparison logic.
Completion checklist:
- Every function prints exactly its required line and one trailing newline.
- All dynamic text and numbers come from parameters.
- The complete C++20 target is warning-clean and reads no stdin.
Run from project root: ./course check 5.x
*/
#include "report.h"

#include <iostream>

void printHeading(std::string_view heading)
{
    std::cout << heading << '\n';
}

void printPerson(int number, std::string_view name, int age)
{
    std::cout << "Person " << number << ": " << name << " (age " << age << ")\n";
}

void printOlderPerson(std::string_view name, int age)
{
    std::cout << "Older person: " << name << " (age " << age << ")\n";
}

void printAgeDifference(int difference)
{
    std::cout << "Age difference: " << difference << " years\n";
}

void printFirstOlderCheck(std::string_view name)
{
    std::cout << "First-argument older check: " << name << '\n';
}

void printTieResult(std::string_view name)
{
    std::cout << "Tie rule: first person wins\n";
    std::cout << "Tie selected: " << name << '\n';
}
