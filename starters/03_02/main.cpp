/*
Lesson 3.2 - The debugging process
LearnCpp: https://www.learncpp.com/cpp-tutorial/the-debugging-process/
What is practiced:
- Follow a complete root-cause debugging process using breakpoints, parameter
  inspection, a minimal repair, and full regression retesting.
Explicit expected behavior:
- Four loose tiles plus three cracked tiles produce seven repair units.
- Seven repair units at 15 minutes each produce 105 repair minutes.
Debugging procedure:
1. Run this untouched program once and record its exact output.
2. Break immediately after countRepairUnits() and inspect repairUnits.
3. Step into estimateRepairMinutes() and inspect both parameter values.
4. Mark the first point where actual state differs from expected state.
5. Explain why that state produces the visible symptom before editing.
6. Make one root-cause repair, then rerun and verify both output lines.
File and function responsibilities:
- main owns the fixed inputs and coordinates the three module functions.
- repair_plan.h publishes the interface used here.
- repair_plan.cpp owns arithmetic and all report output.
Constraints:
- Keep looseTiles equal to 4, crackedTiles equal to 3, and minutes per unit
  equal to 15.
- Keep main free of direct output and do not hard-code results.
- Include the header, never the implementation file.
- Use explicit std:: qualification where standard-library names are needed.
Exact expected output:
Repair units: 7
Estimated repair time: 105 minutes
Completion checklist:
- The failure was reproduced before editing.
- The first incorrect transfer of state can be described.
- Only the responsible production behavior was repaired.
- The final program builds without warnings and prints exactly as required.
Run from project root: ./course check 3.2
*/
#include "repair_plan.h"

int main()
{
    int looseTiles{ 4 };
    int crackedTiles{ 3 };
    int repairUnits{ countRepairUnits(looseTiles, crackedTiles) };
    int repairMinutes{ estimateRepairMinutes(crackedTiles, 15) };

    printRepairPlan(repairUnits, repairMinutes);
    return 0;
}
