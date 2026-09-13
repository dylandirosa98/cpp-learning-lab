/*
Lesson 3.x - Chapter 3 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
Practice:
- Preserve a small guarded reporting interface during a multi-file debug task.
- Keep observed calculations separate from presentation code.
Expected behavior:
- Print isolated results 7 and 4, then courier CX-17 values 20, 15, 35, and 9.
- Labels, punctuation, ordering, and newlines must match the expected output.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_x.
2. Place primary breakpoints in route.cpp at missionMinutes and the battery
   return; no initial breakpoint belongs in this declaration-only header.
3. Watch outbound and returning in missionMinutes and Step Into leg calls.
4. Inspect Frames at combineSegments to identify each active caller path.
5. Watch missionMinutes, travelUnits, and reserveUnits in the battery helper.
6. After repairs, Step Over printChecks and printMission and verify stdout.
File and function responsibilities:
- report.h declares printChecks and printMission without defining either.
- report.cpp implements both functions and owns all console output.
- route.h/route.cpp own calculations; main passes calculated values to reports.
Constraints:
- Keep the unique guard and both declarations with their current signatures.
- Do not add function bodies, streams, .cpp includes, or std imports here.
Exact expected output:
Check combine(3, 4): 7
Check battery(10): 4
Courier run: CX-17
Outbound minutes: 20
Return minutes: 15
Total minutes: 35
Battery units: 9
Completion checklist:
- Header remains declaration-only and independently guarded.
- Reporting declarations match their definitions and all call sites.
- Complete program builds warning-free and prints seven exact lines.
Run from project root: ./course check 3.x
*/
#ifndef CPP_LEARNING_LAB_REPORT_H
#define CPP_LEARNING_LAB_REPORT_H

void printChecks(int combinedMinutes, int batteryUnits);
void printMission(int outbound, int returning, int total, int batteryUnits);

#endif
