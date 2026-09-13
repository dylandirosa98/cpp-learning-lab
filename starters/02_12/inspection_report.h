/*
Lesson 2.12 - Header guards
LearnCpp: https://www.learncpp.com/cpp-tutorial/header-guards/
Requirements and exact file map:
- This entire file must use a traditional guard named exactly
  CPP_LEARNING_LAB_INSPECTION_REPORT_H: test that name before the contents,
  define the same name when contents begin, and close the guard at the end.
- Keep #include "roof_metrics.h" and the existing void
  printAnchorChecks(checks) declaration inside this guard. Add no function body
  and do not use a nonstandard guard shortcut.
- roof_metrics.h has the distinct CPP_LEARNING_LAB_ROOF_METRICS_H guard and
  declares int-returning requiredAnchorChecks(roofSections).
- main.cpp includes roof_metrics.h directly and this header second, includes
  <iostream>, and owns both function definitions after main. Its output uses
  std::cout explicitly; no file imports the entire standard namespace.
Formula and sample input:
- required checks = roof sections * 2 checks per section; 6 sections produce 12.
Constraints:
- Counts are non-negative whole numbers that fit in int. No validation or user
  input is required.
Expected complete program output:
Required anchor checks: 12
Completion checklist:
- This guard uses its exact required name, distinct from roof_metrics.h.
- The include and declaration are both between the opening and closing guard.
- The header has one declaration and no function definition.
- The complete program prints the exact line above, including its newline.
Run from project root: ./course check 2.12
*/
// TODO: Enclose the include and declaration in the required named guard.
#include "roof_metrics.h"

void printAnchorChecks(int checks);
