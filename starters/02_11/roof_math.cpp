/*
Lesson 2.11 - Header files
LearnCpp: https://www.learncpp.com/cpp-tutorial/header-files/
Requirements and exact file map:
- roof_math.h contains only the declarations for int-returning panelArea(width,
  height) and totalArea(areaPerPanel, panelCount). No definitions belong there,
  and no header guard is required for this lesson.
- This file includes "roof_math.h" first and provides the only matching
  definitions of panelArea and totalArea. Add no output and no library include.
- main.cpp includes "roof_math.h" and <iostream>, supplies the fixed inputs,
  and prints with std::cout. Never include this .cpp file from another file,
  and do not import the entire standard namespace.
Formula and sample inputs:
- panel area = width * height; width 12 and height 10 produce 120.
- total area = area per panel * panel count; area 120 and count 4 produce 480.
Constraints:
- Parameters are non-negative whole numbers that fit in int. Return int values;
  input validation and floating-point arithmetic are outside this exercise.
Expected complete program output:
Roof coverage: 480 sq ft
Completion checklist:
- Each definition still exactly matches its declaration in roof_math.h.
- Each function returns the result described by its formula.
- This file performs no console output and main prints the exact line above.
- All three source/header responsibilities remain separated as listed.
Run from project root: ./course check 2.11
*/
#include "roof_math.h"

int panelArea(int width, int height)
{
    // TODO: Return the rectangular area represented by width and height.
    return width + height;
}

int totalArea(int areaPerPanel, int panelCount)
{
    // TODO: Return the coverage for panelCount panels of areaPerPanel each.
    return areaPerPanel + panelCount;
}
