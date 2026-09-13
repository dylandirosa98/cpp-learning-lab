/*
Lesson 2.13 - How to design your first programs
LearnCpp: https://www.learncpp.com/cpp-tutorial/how-to-design-your-first-programs/
Requirements:
- Build one work-order pipeline from fixed inputs. Keep calculation separate
  from presentation, and keep main focused on data and function calls.
- Include <iostream> and qualify console output as std::cout. Do not add
  a global namespace-import directive.
File and function map (all remain in main.cpp):
- calculateTotalDefects takes flashingDefects and fastenerDefects and returns
  their combined int count.
- calculateRepairMinutes takes defects and minutesPerDefect and returns the
  total int duration.
- printWorkOrder takes both calculated values, returns no value, and performs
  all output using the required labels.
- main uses exactly 3 flashing defects, 5 fastener defects, and 12 minutes per
  defect, then gives both calculated results to printWorkOrder.
Formulas and sample case:
- total defects = flashing defects + fastener defects: 3 + 5 = 8.
- repair minutes = total defects * minutes per defect: 8 * 12 = 96.
Constraints:
- Defect counts and minutes are non-negative whole numbers that fit in int.
  No validation, user input, or floating-point arithmetic is required.
Expected complete program output:
Defects logged: 8
Estimated repair time: 96 minutes
Completion checklist:
- Each function keeps its existing signature and single responsibility.
- main uses the exact sample inputs and performs no direct output.
- printWorkOrder produces both exact lines in order, each ending in a newline.
- Both formulas produce the sample results 8 and 96.
Run from project root: ./course check 2.13
*/
#include <iostream>

int calculateTotalDefects(int flashingDefects, int fastenerDefects)
{
    // TODO: Return one total that accounts for both defect categories.
    return flashingDefects - fastenerDefects;
}

int calculateRepairMinutes(int defects, int minutesPerDefect)
{
    // TODO: Return the duration for all defects at the per-defect rate.
    return defects + minutesPerDefect;
}

void printWorkOrder(int defects, int repairMinutes)
{
    std::cout << "Defects logged: " << defects << '\n';
    std::cout << "Estimated repair time: " << repairMinutes << " minutes\n";
}

int main()
{
    int defects{ calculateTotalDefects(3, 5) };
    int repairMinutes{ calculateRepairMinutes(defects, 12) };
    printWorkOrder(defects, repairMinutes);
    return 0;
}
