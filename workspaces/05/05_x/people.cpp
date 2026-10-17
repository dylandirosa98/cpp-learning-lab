/*
Lesson 5.x - Chapter 5 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-5-summary-and-quiz/
Tasks:
- Build an owning full name from two read-only views without hard-coding names.
- Calculate the absolute age difference and select the older supplied name.
Function responsibilities:
- composeFullName copies firstName into std::string, adds one space, then lastName.
- ageDifference subtracts the smaller supplied age from the larger supplied age.
- selectOlderName returns firstName when firstAge >= secondAge, including ties.
Expected output from the complete program:
- Composed names appear as "Ada Lovelace" and "Charles Babbage".
- Ages 36 and 79 yield difference 43; Charles wins normally and Ada wins the tie.
Constraints:
- Include people.h first and perform no input or output in this module.
- Never return a view into a local or temporary std::string; return an input view.
- Do not embed either person's full name, age, or the calculated difference here.
Completion checklist:
- The composed std::string owns its characters after this function returns.
- Age difference is non-negative regardless of argument order.
- Tie behavior is deterministic and all C++20 compilation is warning-clean.
Run from project root: ./course check 5.x
*/
#include "people.h"

std::string composeFullName(std::string_view firstName, std::string_view lastName)
{
    std::string fullName{ firstName };
    fullName += ' ';
    fullName += lastName;
    return fullName;
}

int ageDifference(int firstAge, int secondAge)
{
    if (firstAge >= secondAge)
        return firstAge - secondAge;

    return secondAge - firstAge;
}

std::string_view selectOlderName(std::string_view firstName, int firstAge, std::string_view secondName, int secondAge)
{
    if (firstAge >= secondAge)
        return firstName;

    return secondName;
}
