/*
Lesson 3.8 - Using an integrated debugger: Watching variables
LearnCpp: https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-watching-variables/
Practice:
- Inspect parameters and intermediate locals in CLion's Watches pane.
- Relate each state transition to the stated inventory behavior.
Expected behavior:
- Begin with 52 reserve units, issue 17, and receive 4 returned units.
- The final reserve count must be 39 units.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_08.
2. Put the initial breakpoint on the afterIssue initialization.
3. Start Debug and add these watches exactly: available, issued, returned,
   afterIssue, and finalCount.
4. Step Over each initialization and record when each watch becomes available.
5. Compare afterIssue and finalCount before returning to main.
6. Repair the source, restart, and confirm the corrected transitions.
File and function responsibilities:
- remainingUnits performs the two inventory transitions and returns the count.
- main provides fixed inputs and prints the final reserve report.
Constraints:
- Keep both named local variables and the existing function interface.
- Do not hard-code 39, add diagnostics, or import the std namespace.
Exact expected output:
Reserve remaining: 39 units
Completion checklist:
- All five required watches are inspected at the specified stops.
- Issued and returned units affect state according to their meanings.
- Compilation is warning-free and output is exactly one line.
Run from project root: ./course check 3.8
*/
#include <iostream>

int remainingUnits(int available, int issued, int returned)
{
    int afterIssue{ available - issued };
    int finalCount{ afterIssue + returned };
    return finalCount;
}

int main()
{
    int reserve{ remainingUnits(52, 17, 4) };
    std::cout << "Reserve remaining: " << reserve << " units\n";
    return 0;
}
