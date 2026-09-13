/*
Lesson 2.x - Chapter 2 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
Requirements:
- Own all inspection arithmetic, match the public declarations exactly, and
  perform no console output. Include the paired header first.
File and function map:
- inspection.h guards and declares calculateRiskPoints and estimateCrewHours.
- inspection.cpp defines those two int-returning functions.
- report.h/report.cpp own the printInspection interface and all console output.
- main.cpp includes both headers, supplies fixed inputs, and connects modules.
Formulas and sample case:
- risk points = moisture readings * 3 + damaged tiles * 2.
- crew hours = risk points / 4 using integer division.
- For 5 moisture readings and 4 damaged tiles: risk is 23; hours is 5 because
  the remainder from 23 divided by 4 is discarded.
Constraints:
- Parameters are non-negative whole numbers that fit in int. No rounding up,
  validation, input, floating-point arithmetic, or output belongs here.
Expected complete program output:
Roof inspection: R-204
Risk points: 23
Crew hours: 5
Completion checklist:
- Both existing definitions match inspection.h and use the required formulas.
- This file includes inspection.h first and performs no console output.
- report.cpp remains the only output implementation.
- The complete program produces the three exact lines above.
Run from project root: ./course check 2.x
*/
#include "inspection.h"

int calculateRiskPoints(int moistureReadings, int damagedTiles)
{
    // TODO: Weight each input by its specified points and return their total.
    return moistureReadings * 3 + damagedTiles * 2;
}

int estimateCrewHours(int riskPoints)
{
    // TODO: Convert risk points to whole four-point crew-hour units.
    return riskPoints/4;
}
