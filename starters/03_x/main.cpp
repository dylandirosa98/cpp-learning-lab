/*
Lesson 3.x - Chapter 3 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
Practice:
- Combine breakpoints, stepping, watches, call stacks, and regression checks.
- Diagnose behavior across independently compiled calculation and report files.
Expected behavior:
- Outbound segments 12 and 8 produce 20 minutes; return segments 9 and 6
  produce 15. The total is 35 minutes. One battery unit is needed per five
  mission minutes, plus two reserve units, for a total of 9.
CLion Debug procedure:
1. Select the Debug CMake profile, build lesson_03_x, and record starter output.
2. Break on the first statement in missionMinutes in route.cpp and on the
   return statement in batteryUnitsNeeded.
3. In missionMinutes, watch outbound and returning and Step Into both calls.
4. At combineSegments, inspect Frames from main through the active function.
5. In batteryUnitsNeeded, watch missionMinutes, travelUnits, and reserveUnits.
6. Repair one observed behavior at a time and rerun both checks and the report.
File and function responsibilities:
- route.h publishes calculations; route.cpp implements them without output.
- report.h publishes presentation; report.cpp owns every console statement.
- main performs the two isolated checks, obtains mission values, and reports.
Constraints:
- Preserve all files, interfaces, fixed inputs, and module responsibilities.
- Do not hard-code results, add diagnostic streams, or include .cpp files.
Exact expected output:
Check combine(3, 4): 7
Check battery(10): 4
Courier run: CX-17
Outbound minutes: 20
Return minutes: 15
Total minutes: 35
Battery units: 9
Completion checklist:
- Both isolated checks and all integrated report values are correct.
- Required watches and caller paths were recorded before each repair.
- Build is warning-free and output matches all seven lines exactly.
Run from project root: ./course check 3.x
*/
#include "report.h"
#include "route.h"

int main()
{
    int combinedCheck{ combineSegments(3, 4) };
    int batteryCheck{ batteryUnitsNeeded(10) };
    printChecks(combinedCheck, batteryCheck);

    int outbound{ outboundMinutes() };
    int returning{ returnMinutes() };
    int total{ missionMinutes() };
    int batteryUnits{ batteryUnitsNeeded(total) };
    printMission(outbound, returning, total, batteryUnits);
    return 0;
}
