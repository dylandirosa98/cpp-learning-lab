/*
Lesson 2.x - Chapter 2 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
Requirements:
- Own all complete-program console output, match the report declaration exactly,
  and qualify each standard-library name instead of importing its namespace.
File and function map:
- report.h guards and declares void printInspection(riskPoints, crewHours).
- report.cpp includes report.h first, includes <iostream>, and defines that one
  reporting function with the fixed ID R-204 and required labels.
- inspection.h/inspection.cpp declare and define the two calculations.
- main.cpp includes both headers, calculates values, and calls the report once.
Formulas and sample case:
- risk points = moisture readings * 3 + damaged tiles * 2.
- crew hours = risk points / 4 using integer division.
- Inputs 5 and 4 produce 23 risk points and 5 crew hours for this report.
Constraints:
- Values are non-negative whole numbers that fit in int. The ID is always R-204;
  this function performs no calculation, validation, or console input.
Expected complete program output:
Roof inspection: R-204
Risk points: 23
Crew hours: 5
Completion checklist:
- The definition keeps its existing signature and uses both supplied values.
- All three exact lines print in order and each ends with a newline.
- No arithmetic moves here from inspection.cpp, and main performs no output.
- Project headers remain guarded and implementation files remain separate.
Run from project root: ./course check 2.x
*/
#include "report.h"

#include <iostream>

void printInspection(int riskPoints, int crewHours)
{
    std::cout << "Roof inspection: R-204\n";
    std::cout << "Risk points: " << riskPoints << '\n';
    std::cout << "Crew hours: " << crewHours << '\n';
}
