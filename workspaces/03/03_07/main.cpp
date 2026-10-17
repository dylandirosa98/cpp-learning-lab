/*
Lesson 3.7 - Using an integrated debugger: Running and breakpoints
LearnCpp: https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-running-and-breakpoints/
Practice:
- Use persistent breakpoints, Start, Continue, and Run to Cursor.
- Compare repeated calls without changing the execution point artificially.
Expected behavior:
- Accumulate loading stages lasting 14, 9, and 7 minutes in that order.
- The elapsed timeline must finish at 30 minutes.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_07.
2. Put breakpoints on recordStage's return and main's output statement.
3. Start Debug and use Continue through all three recordStage stops.
4. At each stop, note the arguments, originating call, and next statement.
5. Restart, right-click the third update, and choose Run to Cursor.
6. Repair normal source code; do not use Set Next Statement as the fix.
File and function responsibilities:
- recordStage returns elapsed time after adding exactly one stage.
- main owns the accumulated timeline and prints the final report.
Constraints:
- Keep all three stage durations and the recordStage interface.
- Do not hard-code 30, add diagnostics, or import the std namespace.
Exact expected output:
Loading timeline: 30 minutes
Completion checklist:
- The persistent breakpoint is reached exactly three times.
- Each stage continues from the state produced by the prior stage.
- Compilation is warning-free and output is exactly one line.
Run from project root: ./course check 3.7
*/
#include <iostream>

int recordStage(int elapsed, int stageMinutes)
{
    return elapsed + stageMinutes;
}

int main()
{
    int elapsed{};
    elapsed = recordStage(elapsed, 14);
    elapsed = recordStage(elapsed, 9);
    elapsed = recordStage(elapsed, 7);

    std::cout << "Loading timeline: " << elapsed << " minutes\n";
    return 0;
}
