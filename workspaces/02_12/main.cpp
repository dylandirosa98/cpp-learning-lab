/*
Lesson 2.12 - Header guards
LearnCpp: https://www.learncpp.com/cpp-tutorial/header-guards/
Requirements and exact file map:
- roof_metrics.h uses the guard name CPP_LEARNING_LAB_ROOF_METRICS_H and keeps
  the declaration of int-returning requiredAnchorChecks(roofSections) inside
  that complete guard. It contains no function definition.
- inspection_report.h uses the distinct guard name
  CPP_LEARNING_LAB_INSPECTION_REPORT_H. Inside that complete guard, it includes
  "roof_metrics.h" and declares void printAnchorChecks(checks), with no body.
- main.cpp deliberately includes "roof_metrics.h" directly and then includes
  "inspection_report.h", which reaches roof_metrics.h a second time. It also
  includes <iostream>. Keep the existing include arrangement.
- main.cpp contains main followed by the only definitions of
  requiredAnchorChecks and printAnchorChecks. Output uses std::cout explicitly;
  do not import the entire standard namespace or use a nonstandard guard shortcut.
Formula and sample input:
- required checks = roof sections * 2 checks per section.
- For 6 sections, requiredAnchorChecks produces 12 checks.
Constraints:
- The section and check counts are non-negative whole numbers that fit in int.
  No validation or console input is required.
Expected complete program output:
Required anchor checks: 12
Completion checklist:
- Both headers have complete, distinct guards around all of their contents.
- Both declarations match their definitions, and definitions stay after main.
- main calls the calculation with exactly 6 and sends its result to the report.
- Output spelling, spacing, capitalization, value, and newline match exactly.
Run from project root: ./course check 2.12
*/
#include "roof_metrics.h"
#include "inspection_report.h"

#include <iostream>

int main()
{
    printAnchorChecks(requiredAnchorChecks(6));
    return 0;
}

int requiredAnchorChecks(int roofSections)
{
    // TODO: Account for two required checks for every supplied roof section.

    return roofSections * 2;
}

void printAnchorChecks(int checks)
{
    std::cout << "Required anchor checks: " << checks << '\n';
}
