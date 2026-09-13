/*
Lesson 3.6 - Using an integrated debugger: Stepping
LearnCpp: https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-stepping/
Practice:
- Control execution with Step Into, Step Over, and Step Out.
- Trace calculations across function boundaries before editing source code.
Expected behavior:
- Combine warehouse and customer travel, then add one five-minute handoff.
- Inputs 18 and 27 must produce a 50-minute dispatch estimate.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_06.
2. Put the initial breakpoint on the totalMinutes initialization in main.
3. Start Debug, Step Into estimateDispatchMinutes, and follow each statement.
4. Step Into addHandoffMinutes, then use Step Out to return to its caller.
5. Restart at the same breakpoint and Step Over the helper call for comparison.
6. Stop debugging, repair the source, and repeat the trace before checking.
File and function responsibilities:
- addHandoffMinutes adds only the fixed handoff duration.
- estimateDispatchMinutes combines both travel legs and invokes the helper.
- main supplies fixed inputs and prints the completed report line.
Constraints:
- Keep both functions and their signatures. Do not hard-code 50.
- Do not add diagnostic streams or import the std namespace.
Exact expected output:
Dispatch estimate: 50 minutes
Completion checklist:
- The Debug trace enters and leaves both helper functions as expected.
- Each input has a meaningful role in the estimate.
- Compilation is warning-free and output is exactly one line.
Run from project root: ./course check 3.6
*/
#include <iostream>

int addHandoffMinutes(int travelMinutes)
{
    return travelMinutes + 5;
}

int estimateDispatchMinutes(int warehouseLeg, int customerLeg)
{
    int travelMinutes{ warehouseLeg + (customerLeg - warehouseLeg) };
    return addHandoffMinutes(travelMinutes);
}

int main()
{
    int totalMinutes{ estimateDispatchMinutes(18, 27) };
    std::cout << "Dispatch estimate: " << totalMinutes << " minutes\n";
    return 0;
}
