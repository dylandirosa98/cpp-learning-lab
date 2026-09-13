/*
Lesson 2.x - Chapter 2 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
Requirements:
- Build a five-file program with calculation in the inspection module,
  presentation in the report module, and coordination in main.
- main performs no direct console output and never includes a .cpp file.
File and function map:
- inspection.h guards and declares calculateRiskPoints and estimateCrewHours.
- inspection.cpp defines both calculations and performs no output.
- report.h guards and declares printInspection.
- report.cpp defines printInspection and owns all console stream statements.
- main.cpp includes both project headers, calculates both results from the fixed
  inputs, and passes them to printInspection.
Formulas and sample case:
- risk points = moisture readings * 3 + damaged tiles * 2.
- crew hours = risk points / 4 using integer division.
- With 5 moisture readings and 4 damaged tiles, risk is 23 and hours is 5.
Constraints:
- Inputs and results are non-negative whole numbers that fit in int. Integer
  division discards any remainder. No validation or user input is required.
Expected complete program output:
Roof inspection: R-204
Risk points: 23
Crew hours: 5
Completion checklist:
- Each declaration and definition remains in the file assigned above.
- Both headers are used; no implementation file or <iostream> is included here.
- main uses exactly 5 and 4, stores both results, and calls the report once.
- The report module produces the three exact lines above in order.
Run from project root: ./course check 2.x
*/
#include <iostream>

#include "inspection.h"
#include "report.h"

int main()
{
    int riskPoints{ calculateRiskPoints(5, 4) };
    int crewHours{ estimateCrewHours(riskPoints) };
    printInspection(riskPoints, crewHours);
    return 0;
}