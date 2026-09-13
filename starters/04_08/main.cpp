/*
Lesson 4.8 - Floating point numbers
LearnCpp: https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
Practice:
- Calculate with double values instead of discarding fractional information.
- Control floating-point presentation with fixed notation and setprecision.
Task:
1. Inspect how operator precedence groups the current return expression.
2. Change averageTemperature so both readings are added first.
3. Divide the sum by the floating-point value 2.0.
4. Leave the fixed inputs and output formatting in main unchanged.
Function responsibility:
- averageTemperature performs only the reusable calculation.
- main owns the deterministic values and their presentation.
Constraints:
- Do not return 21.25 directly or embed the completed line in a string.
- Keep the function signature, double literals, and formatting manipulators.
Exact expected output:
Average temperature: 21.25 C
Completion checklist:
- The function models the arithmetic mean of its two parameters.
- Exactly two digits appear after the decimal point.
- The program builds warning-free as C++20.
Run from project root: ./course check 4.8
*/
#include <iomanip>
#include <iostream>

double averageTemperature(double morning, double afternoon)
{
    return morning + afternoon / 2.0;
}

int main()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average temperature: " << averageTemperature(18.5, 24.0) << " C\n";
    return 0;
}
