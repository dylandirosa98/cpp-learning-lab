#include "calculations.h"
#include "report.h"

void runCalculation(double leftOperand, char operation, double rightOperand)
{
    bool supported{ isSupportedOperation(operation) };
    bool divisionByZero{ isDivisionByZero(operation, rightOperand) };
    double result{};

    if (supported && !divisionByZero)
        result = calculate(leftOperand, operation, rightOperand);

    printCalculation(leftOperand, operation, rightOperand, supported, divisionByZero, result);
}

int main()
{
    printCalculatorHeading();
    runCalculation(8.0, '+', 2.0);
    runCalculation(8.0, '-', 2.0);
    runCalculation(8.0, '*', 2.5);
    runCalculation(9.0, '/', 4.0);
    runCalculation(5.0, '/', 0.0);
    runCalculation(3.0, '?', 2.0);
    runCalculation(3.0, '?', 0.0);

    double initialHeight{ 100.0 };
    printBallHeading(initialHeight);
    for (int seconds{ 0 }; seconds <= 5; ++seconds)
    {
        double height{ heightAfterSeconds(initialHeight, seconds) };
        printBallHeight(seconds, height);
    }

    return 0;
}
