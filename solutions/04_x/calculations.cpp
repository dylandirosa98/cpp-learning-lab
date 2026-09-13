#include "calculations.h"

bool isSupportedOperation(char operation)
{
    return operation == '+' || operation == '-' || operation == '*' || operation == '/';
}

bool isDivisionByZero(char operation, double rightOperand)
{
    return operation == '/' && rightOperand == 0.0;
}

double calculate(double leftOperand, char operation, double rightOperand)
{
    if (operation == '+')
        return leftOperand + rightOperand;
    if (operation == '-')
        return leftOperand - rightOperand;
    if (operation == '*')
        return leftOperand * rightOperand;
    if (operation == '/')
        return leftOperand / rightOperand;

    return 0.0;
}

double heightAfterSeconds(double initialHeight, int seconds)
{
    constexpr double gravity{ 9.8 };
    double time{ static_cast<double>(seconds) };
    double height{ initialHeight - gravity * time * time / 2.0 };

    if (height < 0.0)
        return 0.0;

    return height;
}
