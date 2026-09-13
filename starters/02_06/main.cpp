/*
Lesson 2.6: Why functions are useful, and how to use them effectively
LearnCpp: https://www.learncpp.com/cpp-tutorial/why-functions-are-useful-and-how-to-use-them-effectively/

What you are practicing:
- Splitting calculation, presentation, and coordination into focused functions.
- Passing one function's result into another function.

Required functions and observable behavior:
- main.cpp must define int calculateRoofArea(int length, int width),
  int calculateRunoffUnits(int area, int rainfallUnits), and
  void printDrainageReport(int area, int runoffUnits).
- main() must calculate with length 12, width 8, and rainfall factor 3, then
  call printDrainageReport once with the two results.
- Only printDrainageReport() writes the two report lines.

Formulas and example:
- roof area = length * width
- runoff units = area * rainfallUnits
- calculateRoofArea(12, 8) returns 96; calculateRunoffUnits(96, 3) returns 288.

Constraints:
- Keep the exact function signatures and use int values.
- The calculation functions return values and perform no console output.
- Do not hard-code the sample results.
- Qualify standard-library names explicitly, such as std::cout; do not use a
  using-directive.

Expected output:
Roof area: 96 square units
Runoff load: 288 units

Completion checklist:
- Both formulas are implemented in their calculation functions.
- The report uses its parameters and matches both output lines exactly.
- main() coordinates the required calls and returns success.

Checker command: ./course check 2.6
*/

#include <iostream>

int calculateRoofArea(int length, int width)
{
    // TODO: Return the product of the supplied dimensions without printing.
    return 0;
}

int calculateRunoffUnits(int area, int rainfallUnits)
{
    // TODO: Return the area scaled by the supplied rainfall factor without printing.
    return 0;
}

void printDrainageReport(int area, int runoffUnits)
{
    // TODO: Print both labeled measurements, in order, using the supplied values.
}

int main()
{
    int area{calculateRoofArea(12, 8)};
    int runoffUnits{calculateRunoffUnits(area, 3)};
    printDrainageReport(area, runoffUnits);

    return 0;
}
