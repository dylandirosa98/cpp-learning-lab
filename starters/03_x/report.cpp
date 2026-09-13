/*
Lesson 3.x - Chapter 3 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
Practice:
- Verify calculated state reaches a dedicated reporting translation unit.
- Keep debugger repairs in the responsible module rather than masking output.
Expected behavior:
- Print checks 7 and 4, then courier CX-17 with times 20, 15, 35 and battery 9.
- Every label and newline must match the seven-line expected output exactly.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_x.
2. Break first in route.cpp at missionMinutes and batteryUnitsNeeded's return.
3. Watch outbound and returning while stepping into both route functions.
4. Inspect Frames at combineSegments and record each caller chain.
5. Watch missionMinutes, travelUnits, and reserveUnits at the battery stop.
6. After repairs, Step Over both report calls and compare console output.
File and function responsibilities:
- printChecks presents two independently calculated regression values.
- printMission presents the fixed ID and four supplied mission values.
- route.cpp performs all calculations; main coordinates and passes arguments.
Constraints:
- Include report.h first and keep all console output in this file.
- Do not calculate replacement values, hard-code result numbers, or import std.
Exact expected output:
Check combine(3, 4): 7
Check battery(10): 4
Courier run: CX-17
Outbound minutes: 20
Return minutes: 15
Total minutes: 35
Battery units: 9
Completion checklist:
- Both functions print only values supplied through their parameters.
- No route calculation or repair is moved into this reporting module.
- Build is warning-free and all seven output lines match exactly.
Run from project root: ./course check 3.x
*/
#include "report.h"

#include <iostream>

void printChecks(int combinedMinutes, int batteryUnits)
{
    std::cout << "Check combine(3, 4): " << combinedMinutes << '\n';
    std::cout << "Check battery(10): " << batteryUnits << '\n';
}

void printMission(int outbound, int returning, int total, int batteryUnits)
{
    std::cout << "Courier run: CX-17\n";
    std::cout << "Outbound minutes: " << outbound << '\n';
    std::cout << "Return minutes: " << returning << '\n';
    std::cout << "Total minutes: " << total << '\n';
    std::cout << "Battery units: " << batteryUnits << '\n';
}
