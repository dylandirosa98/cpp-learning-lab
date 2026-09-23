/*
Lesson 3.x - Chapter 3 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
Practice:
- Maintain a guarded public interface while debugging implementation call flow.
- Use function boundaries to make calculation responsibilities inspectable.
Expected behavior:
- Segment pairs 12 and 8, then 9 and 6, form mission legs 20 and 15.
- Mission total is 35; five minutes consume one unit and two reserves are added.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_x.
2. Break at missionMinutes and batteryUnitsNeeded in route.cpp, not this header.
3. Watch outbound and returning while stepping through missionMinutes.
4. Inspect Frames whenever combineSegments is reached from that function.
5. Watch missionMinutes, travelUnits, and reserveUnits in the battery helper.
6. Return here only to confirm declarations still match repaired definitions.
File and function responsibilities:
- route.h declares all five calculation functions and contains no definitions.
- route.cpp defines those functions and performs no console output.
- report.h/report.cpp own reporting; main coordinates checks and mission calls.
Constraints:
- Keep this unique include guard and every declaration exactly once.
- Do not add definitions, output, implementation includes, or std imports here.
Exact expected output:
Check combine(3, 4): 7
Check battery(10): 4
Courier run: CX-17
Outbound minutes: 20
Return minutes: 15
Total minutes: 35
Battery units: 9
Completion checklist:
- Guard encloses declarations and no function body appears in this header.
- Declarations match route.cpp definitions after all repairs.
- Complete program builds warning-free and prints the seven expected lines.
Run from project root: ./course check 3.x
*/
#ifndef CPP_LEARNING_LAB_ROUTE_H
#define CPP_LEARNING_LAB_ROUTE_H

int combineSegments(int firstMinutes, int secondMinutes);
int outboundMinutes();
int returnMinutes();
int missionMinutes();
int batteryUnitsNeeded(int missionMinutes);

#endif
