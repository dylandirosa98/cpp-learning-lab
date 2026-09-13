#include "report.h"

#include <iomanip>
#include <iostream>

void printCalculatorHeading()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Calculator checks:\n";
}

void printCalculation(double leftOperand, char operation, double rightOperand, bool supported, bool divisionByZero, double result)
{
    std::cout << leftOperand << ' ' << operation << ' ' << rightOperand;

    if (!supported)
    {
        std::cout << " -> error: unsupported operation\n";
        return;
    }

    if (divisionByZero)
    {
        std::cout << " -> error: division by zero\n";
        return;
    }

    std::cout << " = " << result << '\n';
}

void printBallHeading(double initialHeight)
{
    std::cout << "Falling ball from " << initialHeight << " meters:\n";
}

void printBallHeight(int seconds, double height)
{
    std::cout << "At " << seconds << " seconds: " << height << " meters\n";
}
