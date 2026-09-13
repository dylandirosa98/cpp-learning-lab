/*
Lesson 4.x - Chapter 4 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
Tasks:
- Coordinate fixed calculator checks and a fixed falling-ball simulation.
- Use bool validation state and if to keep invalid calls out of calculate.
- Pass every result to report.cpp; main performs no direct output.
Function responsibilities:
- runCalculation derives supported/division states, conditionally calculates,
  and passes operands, states, and result to printCalculation.
 - main runs +, -, *, /, zero-divisor, and two unsupported-char cases.
- main also reports height from 100.0 meters at each whole second 0 through 5.
Expected behavior:
 - Four successes are followed by one division error and two unsupported errors.
- Ball heights are 100.00, 95.10, 80.40, 55.90, 21.60, and ground 0.00.
 - The complete output has fifteen deterministic lines and requires no stdin.
Constraints:
- Do not include iostream or implementation files, and do not print from main.
- Never call calculate unless supported is true and divisionByZero is false.
- Preserve all fixed inputs so output remains stable for automated checking.
Completion checklist:
- bool, char, int, and double each carry the intended kind of value.
- Every calculator path is exercised and invalid arithmetic is skipped.
- Heights are calculated by the calculation module and only then reported.
- The target builds warning-free and output exactly matches the lesson.
Run from project root: ./course check 4.x
*/
#include "calculations.h"
#include "report.h"

void runCalculation(double leftOperand, char operation, double rightOperand) {
    bool supported{ isSupportedOperation(operation) };
    bool divisionByZero{ isDivisionByZero(operation, rightOperand) };
    double result{};

    if (supported && !divisionByZero)
        result = calculate(leftOperand, operation, rightOperand);

    printCalculation(leftOperand, operation, rightOperand, supported, divisionByZero, result);
}

int main() {
    printCalculatorHeading();
    runCalculation(8.0, '+', 2.0);
    runCalculation(8.0, '-', 2.0);
    runCalculation(8.0, '*', 2.5);
    runCalculation(9.0, '/', 4.0);
    runCalculation(5.0, '/', 0.0);
    runCalculation(3.0, '?', 2.0);
    runCalculation(3.0, '?', 0.0);

    double initialHeight{100.0};
    printBallHeading(initialHeight);
    for (int seconds{0}; seconds <= 5; ++seconds) {
        double height{heightAfterSeconds(initialHeight, seconds)};
        printBallHeight(seconds, height);
    }

    return 0;
}
