/*
Lesson 4.x - Chapter 4 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-4-summary-and-quiz/
Tasks:
- Format every double with fixed notation and exactly two decimal places.
- Present successful calculations and both invalid calculator paths.
- Print the falling-ball heading and each supplied height without recalculating.
Function responsibilities:
- printCalculatorHeading prints "Calculator checks:" and configures formatting.
- printCalculation checks unsupported first, division by zero second, then result.
- printBallHeading and printBallHeight print only their supplied values.
Expected behavior:
- Success lines use "left operation right = result".
- Error lines replace the equals/result suffix with the exact requested message.
- The final section starts at 100.00 meters and ends at 0.00 meters at second 5.
Constraints:
- Include report.h first; this is the only file that includes iostream.
- Use supplied bools and values rather than repeating calculation logic.
- Do not read stdin, import namespace std, or hard-code calculated results.
Completion checklist:
- std::fixed and std::setprecision(2) make output stable.
- Both error branches return before the success line is printed.
- Labels, punctuation, spaces, ordering, and newlines exactly match the lesson.
- The complete target builds warning-free.
Run from project root: ./course check 4.x
*/
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

    // TODO: Print and return from the unsupported and zero-division branches.
    if (!supported)
        std::cout << " = " << result << '\n';

    if (divisionByZero)
        std::cout << " = " << result << '\n';

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
