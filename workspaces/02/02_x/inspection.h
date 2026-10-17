/*
Lesson 2.x - Chapter 2 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
Requirements:
- Publish the inspection calculations while keeping their definitions and all
  arithmetic in inspection.cpp. Do not include a .cpp file or add output here.
File and function map:
- inspection.h uses its existing CPP_LEARNING_LAB_INSPECTION_H guard and
  declares int calculateRiskPoints(moistureReadings, damagedTiles) and int
  estimateCrewHours(riskPoints).
- inspection.cpp includes this header first and defines both functions.
- report.h/report.cpp publish and define printInspection for all output.
- main.cpp includes inspection.h and report.h and coordinates the calls.
Formulas and sample case:
- risk points = moisture readings * 3 + damaged tiles * 2.
- crew hours = risk points / 4 using integer division.
- Inputs 5 and 4 produce 23 risk points and 5 whole crew hours.
Constraints:
- Values are non-negative whole numbers that fit in int. Division discards any
  remainder; validation and console input are not required.
Expected complete program output:
Roof inspection: R-204
Risk points: 23
Crew hours: 5
Completion checklist:
- The existing guard encloses both declarations and uses a distinct name.
- Both signatures remain unchanged and no function body appears in this file.
- Calculations remain in inspection.cpp; output remains in report.cpp.
- The complete program produces the three exact lines above.
Run from project root: ./course check 2.x
*/
#ifndef CPP_LEARNING_LAB_INSPECTION_H
#define CPP_LEARNING_LAB_INSPECTION_H

int calculateRiskPoints(int moistureReadings, int damagedTiles);
int estimateCrewHours(int riskPoints);

#endif
