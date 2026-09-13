/*
Lesson 3.9 - Using an integrated debugger: The call stack
LearnCpp: https://www.learncpp.com/cpp-tutorial/using-an-integrated-debugger-the-call-stack/
Practice:
- Inspect complete active caller paths in CLion's Frames view.
- Compare repeated visits to one shared low-level function.
Expected behavior:
- Adjust intake raw reading 12 and outlet raw reading 8 by the same offset 3.
- Report the difference between the independently adjusted channels as 4.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_09.
2. Put the initial breakpoint on applySensorOffset's return statement.
3. Start Debug and, at every hit, open Debug > Frames.
4. Record function names from main through the active top frame.
5. Use Continue between hits and compare the channel paths represented.
6. Repair call flow, restart, and confirm two distinct caller chains.
File and function responsibilities:
- applySensorOffset applies the fixed adjustment to one raw reading.
- sampleIntake and sampleOutlet provide their channel-specific readings.
- ventilationDifference obtains both samples and calculates their difference.
- main prints the completed result.
Constraints:
- Do not change raw readings, offset value, or public function signatures.
- Do not hard-code 4, add diagnostics, or import the std namespace.
Exact expected output:
Ventilation difference: 4
Completion checklist:
- Each breakpoint hit has a recorded caller path.
- Both channel-specific functions participate in the corrected run.
- Compilation is warning-free and output is exactly one line.
Run from project root: ./course check 3.9
*/
#include <iostream>

int applySensorOffset(int rawReading)
{
    return rawReading + 3;
}

int sampleIntake()
{
    return applySensorOffset(12);
}

int sampleOutlet()
{
    return applySensorOffset(8);
}

int ventilationDifference()
{
    int intake{ sampleIntake() };
    int outlet{ sampleIntake() };
    return intake - outlet;
}

int main()
{
    std::cout << "Ventilation difference: " << ventilationDifference() << '\n';
    return 0;
}
