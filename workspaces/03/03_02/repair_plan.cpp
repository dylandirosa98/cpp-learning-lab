/*
Lesson 3.2 - The debugging process
LearnCpp: https://www.learncpp.com/cpp-tutorial/the-debugging-process/
What is practiced:
- Use debugger observations to distinguish a root cause from the later output
  symptom and complete the full locate, explain, repair, and retest cycle.
Explicit expected behavior:
- Repair units equal the sum of four loose and three cracked tiles: seven.
- Repair minutes equal seven units at 15 minutes per unit: 105.
Debugging procedure:
1. Run the untouched program and preserve its output as a baseline.
2. Break after the unit-count call in main and inspect the stored result.
3. Step into the minute estimator and inspect its parameters before its body.
4. Compare each checkpoint with the explicit values above.
5. Repair the earliest disagreement rather than compensating for its symptom.
6. Rerun and verify that both lines remain correct together.
File and function responsibilities:
- This file includes repair_plan.h first and defines its three functions.
- countRepairUnits combines defect categories.
- estimateRepairMinutes converts repair units to time.
- printRepairPlan is the only function that performs output.
- main.cpp supplies inputs and connects these functions.
Constraints:
- Keep signatures synchronized with repair_plan.h.
- Keep all output in printRepairPlan and do not hard-code result values.
- Use explicit std:: qualification and no using namespace std.
Exact expected output:
Repair units: 7
Estimated repair time: 105 minutes
Completion checklist:
- Runtime evidence identifies the first incorrect state.
- Calculations continue to use their parameters and stated contracts.
- The final build is warning-free and stdout matches exactly.
- No implementation file is included from another source file.
Run from project root: ./course check 3.2
*/
#include "repair_plan.h"

#include <iostream>

int countRepairUnits(int looseTiles, int crackedTiles)
{
    return looseTiles + crackedTiles;
}

int estimateRepairMinutes(int repairUnits, int minutesPerUnit)
{
    return repairUnits * minutesPerUnit;
}

void printRepairPlan(int repairUnits, int repairMinutes)
{
    std::cout << "Repair units: " << repairUnits << '\n';
    std::cout << "Estimated repair time: " << repairMinutes << " minutes\n";
}
