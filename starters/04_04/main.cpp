/*
Lesson 4.4 - Signed integers
LearnCpp: https://www.learncpp.com/cpp-tutorial/signed-integers/
What is practiced:
- Store and calculate with negative signed integer quantities.
- Distinguish a truncated integer quotient from its signed remainder.
Required repair:
1. Evaluate -13 divided by 5 using int arithmetic before running the code.
2. Evaluate the matching remainder separately.
3. Inspect the initializer assigned to each result role in the starter.
4. Put division in wholeSteps and remainder arithmetic in remainder.
Calculation contract:
- totalAdjustment remains -13 and intervalCount remains 5.
- Integer division truncates the quotient toward zero rather than rounding.
File responsibilities:
- main owns fixed signed inputs, calculates both results, and presents them.
Constraints:
- Keep all four int objects and both supplied arithmetic expressions.
- Derive results from totalAdjustment and intervalCount.
- Do not hard-code result values, use input, or import std.
Exact expected output:
Whole steps: -2
Remainder: -3
Completion checklist:
- wholeSteps receives the / expression and remainder receives the % expression.
- Negative truncation and the remainder sign were predicted before checking.
- The C++20 build is warning-free and both lines match exactly.
Run from project root: ./course check 4.4
*/
#include <iostream>

int main()
{
    int totalAdjustment{ -13 };
    int intervalCount{ 5 };
    int wholeSteps{ totalAdjustment % intervalCount };
    int remainder{ totalAdjustment / intervalCount };

    std::cout << "Whole steps: " << wholeSteps << '\n';
    std::cout << "Remainder: " << remainder << '\n';
    return 0;
}
