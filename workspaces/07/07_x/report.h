/*
Lesson 7.x - Chapter 7 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
Tasks:
- Declare heading, sample-line, and summary presentation functions.
- Place the complete presentation interface in namespace Report.
Function responsibilities:
- printHeading accepts and displays the configured target sample count.
- printSample formats supplied ID, raw, and calibrated values.
- printSummary displays supplied legacy, default, and average values.
Expected behavior from the complete program:
- Exactly eight lines form the deterministic field survey report.
Constraints:
- Keep this header declaration-only, include-guarded, and stream-free.
- Do not expose survey calculations or configuration through this interface.
Completion checklist:
- Function parameters carry every dynamic value needed for presentation.
- All declarations are inside Report and the include guard.
- The complete target builds warning-free and passes ./course check 7.x.
Run from project root: ./course check 7.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER7_REPORT_H
#define CPP_LEARNING_LAB_CHAPTER7_REPORT_H

namespace Report
{
    void printHeading(int targetSamples);
    void printSample(int id, int rawReading, int calibratedReading);
    void printSummary(int legacyFirst, int defaultFirst, int average);
}

#endif
