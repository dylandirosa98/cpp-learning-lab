/*
Lesson 2.11 - Header files
LearnCpp: https://www.learncpp.com/cpp-tutorial/header-files/
Requirements and exact file map:
- This file is the roof_math public interface. Keep exactly the two existing
  int-returning declarations: panelArea takes width and height, and totalArea
  takes areaPerPanel and panelCount.
- Do not put function bodies or an #include for roof_math.cpp in this header.
  No other declaration or include is needed. A header guard is not required
  until lesson 2.12.
- roof_math.cpp includes this header first and owns both matching definitions.
- main.cpp includes this header and <iostream>, calls both functions, and uses
  std::cout explicitly. No file imports the entire standard namespace.
Formula and sample inputs:
- panel area = width * height, so dimensions 12 and 10 produce 120.
- total area = area per panel * panel count, so 120 and 4 produce 480.
Constraints:
- All values are non-negative whole numbers that fit in int. No validation,
  console input, floating-point calculation, or unit conversion is required.
Expected complete program output:
Roof coverage: 480 sq ft
Completion checklist:
- Both declarations remain in this header with their existing names, return
  types, parameter types, and parameter order.
- This header contains declarations only; both definitions remain in
  roof_math.cpp.
- The complete program prints the exact line above, including its newline.
Run from project root: ./course check 2.11
*/
int panelArea(int width, int height);
int totalArea(int areaPerPanel, int panelCount);
