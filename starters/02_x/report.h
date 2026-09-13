/*
Lesson 2.x - Chapter 2 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
Requirements:
- Publish only the reporting interface. Keep its definition, <iostream>, and
  every console-output statement in report.cpp.
File and function map:
- report.h uses its existing CPP_LEARNING_LAB_REPORT_H guard and declares void
  printInspection(riskPoints, crewHours).
- report.cpp includes this header first and defines printInspection.
- inspection.h/inspection.cpp declare and define the two calculations.
- main.cpp includes both headers and passes the calculated values to the report.
Formulas and sample case:
- risk points = moisture readings * 3 + damaged tiles * 2.
- crew hours = risk points / 4 using integer division.
- Inputs 5 and 4 produce the report values 23 risk points and 5 crew hours.
Constraints:
- Report values are non-negative whole numbers that fit in int. The inspection
  ID is fixed as R-204; no validation or console input is required.
Expected complete program output:
Roof inspection: R-204
Risk points: 23
Crew hours: 5
Completion checklist:
- The existing distinct guard encloses the unchanged declaration.
- No function body, <iostream>, std::cout, or .cpp include appears here.
- report.cpp remains the only output implementation.
- The complete program produces the three exact lines above.
Run from project root: ./course check 2.x
*/
#ifndef CPP_LEARNING_LAB_REPORT_H
#define CPP_LEARNING_LAB_REPORT_H

void printInspection(int riskPoints, int crewHours);

#endif
