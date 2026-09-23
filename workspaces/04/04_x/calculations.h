/*
Lesson 4.x - Chapter 4 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
Tasks:
- Publish the calculator validation, calculator arithmetic, and ball-height
  interfaces used by main.cpp.
- Keep this header declaration-only and protected by its unique include guard.
Function responsibilities:
- isSupportedOperation reports whether a char is +, -, *, or /.
- isDivisionByZero reports division with a right operand of 0.0.
- calculate returns the double result for a valid supported operation.
- heightAfterSeconds returns a double height for an int elapsed time.
Expected behavior:
- Valid arithmetic includes 8 + 2 = 10, 8 - 2 = 6, 8 * 2.5 = 20, and
  9 / 4 = 2.25. Invalid cases are rejected before calculate is called.
- A ball dropped from 100 meters has heights 100.00 through 21.60 at seconds
  0 through 4 and is clamped to 0.00 at second 5.
Constraints:
- Do not add definitions, streams, input, namespace imports, or a .cpp include.
- Preserve every declaration and keep parameter types consistent with definitions.
Completion checklist:
- The guard encloses all four declarations and has a matching #endif.
- Types express their roles: bool status, char operation, double values, int time.
- The complete target builds warning-free and prints the exact expected output.
Run from project root: ./course check 4.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER4_CALCULATIONS_H
#define CPP_LEARNING_LAB_CHAPTER4_CALCULATIONS_H

bool isSupportedOperation(char operation);
bool isDivisionByZero(char operation, double rightOperand);
double calculate(double leftOperand, char operation, double rightOperand);
double heightAfterSeconds(double initialHeight, int seconds);

#endif
