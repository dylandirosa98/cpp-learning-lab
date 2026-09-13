/*
Lesson 3.2 - The debugging process
LearnCpp: https://www.learncpp.com/cpp-tutorial/the-debugging-process/
What is practiced:
- Reproduce a defect, locate its root cause with runtime evidence, understand
  it, plan a focused repair, make the repair, and retest the complete program.
Explicit expected behavior:
- Four loose tiles and three cracked tiles produce seven repair units.
- Seven units at 15 minutes each produce 105 repair minutes.
Debugging procedure:
1. Run the untouched program and record both lines as the reproduction.
2. Break in main after countRepairUnits() and confirm the stored unit count.
3. Step into estimateRepairMinutes() and inspect both received parameters.
4. Find the first state that disagrees with the behavior stated above.
5. Explain that disagreement before making one root-cause repair.
6. Rerun from the beginning and verify both report lines.
File and function responsibilities:
- repair_plan.h publishes the three repair-plan function declarations only.
- repair_plan.cpp owns calculations and report presentation.
- main.cpp owns fixed inputs and coordinates the calculation pipeline.
Constraints:
- Keep declarations and definitions matching and retain the header guard.
- Do not include a .cpp file or move function bodies into this header.
- Use explicit std:: qualification and no using namespace std.
Exact expected output:
Repair units: 7
Estimated repair time: 105 minutes
Completion checklist:
- The first incorrect runtime state and its cause can be explained.
- The smallest responsible production change was made.
- The program builds without warnings and prints the exact two lines.
- Calculations remain in the module and main remains the coordinator.
Run from project root: ./course check 3.2
*/
#ifndef CPP_LEARNING_LAB_REPAIR_PLAN_H
#define CPP_LEARNING_LAB_REPAIR_PLAN_H

int countRepairUnits(int looseTiles, int crackedTiles);
int estimateRepairMinutes(int repairUnits, int minutesPerUnit);
void printRepairPlan(int repairUnits, int repairMinutes);

#endif
