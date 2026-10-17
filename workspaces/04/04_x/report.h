/*
Lesson 4.x - Chapter 4 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
Tasks:
- Publish the presentation-only interface for calculator and ball results.
- Keep the header declaration-only and protect it from repeated inclusion.
Function responsibilities:
- printCalculatorHeading establishes the calculator heading and number format.
- printCalculation chooses success or one of two error presentations from bools.
- printBallHeading prints the supplied starting height.
- printBallHeight prints one supplied time and calculated height.
Expected behavior:
- Every double is shown with exactly two decimal places.
- Unsupported operation and division-by-zero text must match the lesson output.
- The ball section prints the heading followed by seconds 0 through 5.
Constraints:
- Do not calculate results, validate operations, read input, or emit output here.
- Keep all four declarations and their parameter order aligned with report.cpp.
- Do not use #pragma once or import the std namespace.
Completion checklist:
- A unique include guard encloses only the four declarations.
- bool state is passed explicitly to the calculation reporter.
- Definitions and call sites match these declarations exactly.
- The complete target builds warning-free and prints all expected lines.
Run from project root: ./course check 4.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER4_REPORT_H
#define CPP_LEARNING_LAB_CHAPTER4_REPORT_H

void printCalculatorHeading();
void printCalculation(double leftOperand, char operation, double rightOperand, bool supported, bool divisionByZero, double result);
void printBallHeading(double initialHeight);
void printBallHeight(int seconds, double height);

#endif
