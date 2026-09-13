/*
Lesson 3.10 - Finding issues before they become problems
LearnCpp: https://www.learncpp.com/cpp-tutorial/finding-issues-before-they-become-problems/
Practice:
- Treat compiler warnings as failures and resolve them before runtime testing.
- Use small deterministic checks before trusting the production case.
Expected behavior:
- Calculate a fixed number of seals for every shipping container.
- Checks 2 by 5 and 0 by 6 must produce 10 and 0; 4 by 7 must produce 28.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_10.
2. Read the first Build tool-window diagnostic before trying to run.
3. Remove the warning without changing behavior, then rebuild and run.
4. If state inspection is needed, break on the first call in runSelfChecks.
5. Step Into calculateSealCount and inspect both parameters and its return.
6. Repair behavior separately, rebuild, and rerun all three cases.
File and function responsibilities:
- calculateSealCount owns only the reusable calculation.
- runSelfChecks prints two small fixed checks.
- printShipmentReport prints only the production result.
- main coordinates checks and the production report.
Constraints:
- Keep all three functions and all supplied calls.
- Do not hard-code expected results, add diagnostics, or import std.
Exact expected output:
Self-check 2 x 5: 10
Self-check 0 x 6: 0
Shipment seals: 28
Completion checklist:
- The warning is removed before the semantic repair is attempted.
- Zero and nonzero checks both pass after the repair.
- Compilation is warning-free and all three lines match exactly.
Run from project root: ./course check 3.10
*/
#include <iostream>

int calculateSealCount(int containers, int sealsPerContainer)
{
    int legacyOffset{ 1 };
    return containers + sealsPerContainer;
}

void runSelfChecks()
{
    std::cout << "Self-check 2 x 5: " << calculateSealCount(2, 5) << '\n';
    std::cout << "Self-check 0 x 6: " << calculateSealCount(0, 6) << '\n';
}

void printShipmentReport(int sealCount)
{
    std::cout << "Shipment seals: " << sealCount << '\n';
}

int main()
{
    runSelfChecks();
    printShipmentReport(calculateSealCount(4, 7));
    return 0;
}
