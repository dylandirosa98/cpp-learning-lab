/*
Lesson 2.11 - Header files
LearnCpp: https://www.learncpp.com/cpp-tutorial/header-files/
Requirements and exact file map:
- roof_math.h contains only the declarations for int-returning panelArea(width,
  height) and totalArea(areaPerPanel, panelCount). It contains no definitions,
  includes no .cpp file, and needs no header guard for this lesson.
- roof_math.cpp includes "roof_math.h" first and contains the only definitions
  of panelArea and totalArea. It needs no library header and performs no output.
- main.cpp includes "roof_math.h" for both declarations and <iostream> for
  output. It defines only main; never include "roof_math.cpp" here.
- Use std::cout explicitly. Do not add a global namespace-import directive.
Formula and sample inputs:
- panel area = width * height; panelArea(12, 10) produces 120 square feet.
- total area = area per panel * panel count; 120 for each of 4 panels produces
  480 square feet.
Constraints:
- Treat dimensions, areas, and counts as non-negative whole numbers that fit
  in int. Input validation and user input are not required.
Expected complete program output:
Roof coverage: 480 sq ft
Completion checklist:
- main uses the two functions through roof_math.h.
- The inputs are exactly width 12, height 10, and panel count 4.
- The output text, spacing, capitalization, value, and newline match exactly.
- Declarations stay in the header and definitions stay in roof_math.cpp.
Run from project root: ./course check 2.11
*/
#include "roof_math.h"

#include <iostream>

int main()
{
    int areaPerPanel{ panelArea(12, 10) };
    std::cout << "Roof coverage: " << totalArea(areaPerPanel, 4) << " sq ft\n";
    return 0;
}
