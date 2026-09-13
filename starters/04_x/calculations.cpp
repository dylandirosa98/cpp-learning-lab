/*
Lesson 4.x - Chapter 4 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
Tasks:
- Complete validation for all four operation chars and division by zero.
- Dispatch valid double arithmetic with if statements.
- Implement falling distance and clamp height at the ground.
Function responsibilities:
- isSupportedOperation accepts only +, -, *, and /.
- isDivisionByZero is true only for '/' with a 0.0 right operand.
- calculate handles each supported operation; main prevents invalid calls.
- heightAfterSeconds uses height = initialHeight - gravity * time * time / 2.
Expected behavior:
- Fixed calculator cases produce 10.00, 6.00, 20.00, and 2.25; invalid
  division and '?' are reported as errors rather than calculated.
- With gravity 9.8 and initial height 100.0, seconds 0..5 produce 100.00,
  95.10, 80.40, 55.90, 21.60, and 0.00 meters.
Constraints:
- Include calculations.h first and perform no console input or output here.
- Explicitly convert int seconds to double before squaring it.
- Return 0.0 for defensive unsupported dispatch and for below-ground height.
Completion checklist:
- Every supported char follows its own arithmetic path.
- Division by zero is identified before main calls calculate.
- The physics formula uses 9.8, squares time, and never returns below 0.0.
- The complete target is warning-clean and output is exact.
Run from project root: ./course check 4.x
*/
#include "calculations.h"

bool isSupportedOperation(char operation)
{
    // TODO: Accept each of the four basic calculator operation chars.
    return operation == '+';
}

bool isDivisionByZero(char operation, double rightOperand)
{
    // TODO: Return true only for division whose right operand is zero.
    return operation == '/' && rightOperand != 0.0;
}

double calculate(double leftOperand, char operation, double rightOperand)
{
    // TODO: Select +, -, *, or / from operation and return its double result.
    if (operation == '+')
        return leftOperand + rightOperand;

    return 0.0;
}

double heightAfterSeconds(double initialHeight, int seconds)
{
    constexpr double gravity{ 9.8 };
    double time{ static_cast<double>(seconds) };
    double height{ initialHeight - gravity * time };

    // TODO: Square time, divide falling distance by two, and clamp at ground.
    if (height < 0.0)
        return height;

    return height;
}
