/*
Lesson 2.12 - Header guards
LearnCpp: https://www.learncpp.com/cpp-tutorial/header-guards/
Requirements and exact file map:
- This entire file must use a traditional guard named exactly
  CPP_LEARNING_LAB_ROOF_METRICS_H: test that name before the contents, define
  the same name when contents begin, and close the guard after the declaration.
- Keep only the existing int-returning requiredAnchorChecks(roofSections)
  declaration inside the guard. Do not add a body, include, or guard shortcut.
- inspection_report.h has its own CPP_LEARNING_LAB_INSPECTION_REPORT_H guard
  and includes this header inside that guard.
- main.cpp includes this header directly and through inspection_report.h, then
  defines requiredAnchorChecks after main. It uses <iostream> and std::cout for
  reporting; no file imports the entire standard namespace.
Formula and sample input:
- required checks = roof sections * 2 checks per section; 6 sections produce 12.
Constraints:
- Counts are non-negative whole numbers that fit in int. No validation or user
  input is required.
Expected complete program output:
Required anchor checks: 12
Completion checklist:
- The opening test and definition use the exact same required guard name.
- The closing directive comes after the declaration, protecting the whole file.
- The header still contains one declaration and no function definitions.
- The complete program prints the exact line above, including its newline.
Run from project root: ./course check 2.12
*/
// TODO: Enclose this whole interface in the required named traditional guard.

#ifndef CPP_LEARNING_LAB_ROOF_METRICS_H
#define CPP_LEARNING_LAB_ROOF_METRICS_H
int requiredAnchorChecks(int roofSections);

#endif
