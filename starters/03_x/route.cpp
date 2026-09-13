/*
Lesson 3.x - Chapter 3 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-3-summary-and-quiz/
Practice:
- Trace nested calculation calls with stepping, watches, and call-stack frames.
- Use isolated checks to distinguish helper defects from integration defects.
Expected behavior:
- Outbound time is 12 plus 8; return time is 9 plus 6; mission time is 35.
- Battery need is one unit per five mission minutes plus two reserve units.
CLion Debug procedure:
1. Select the Debug CMake profile and build target lesson_03_x.
2. Break on missionMinutes' first local and batteryUnitsNeeded's return.
3. Watch outbound and returning, Step Into each leg call, and continue into
   combineSegments.
4. At each combination, inspect Frames and record the complete caller path.
5. At the battery stop, watch missionMinutes, travelUnits, and reserveUnits.
6. Repair one observation at a time, restart, and compare all repeated paths.
File and function responsibilities:
- combineSegments combines exactly two segment durations.
- outboundMinutes and returnMinutes supply their fixed route segments.
- missionMinutes obtains both legs and combines them.
- batteryUnitsNeeded derives travel and reserve requirements without output.
Constraints:
- Include route.h first and keep this module independent of iostream.
- Do not change fixed inputs, hard-code expected results, or add diagnostics.
Exact expected output:
Check combine(3, 4): 7
Check battery(10): 4
Courier run: CX-17
Outbound minutes: 20
Return minutes: 15
Total minutes: 35
Battery units: 9
Completion checklist:
- Recorded caller paths represent both named mission legs.
- Watched battery locals implement travel consumption plus reserve inventory.
- Build is warning-free and the complete output matches all seven lines.
Run from project root: ./course check 3.x
*/
#include "route.h"

int combineSegments(int firstMinutes, int secondMinutes)
{
    return firstMinutes + secondMinutes;
}

int outboundMinutes()
{
    return combineSegments(12, 8);
}

int returnMinutes()
{
    return combineSegments(9, 6);
}

int missionMinutes()
{
    int outbound{ outboundMinutes() };
    int returning{ outboundMinutes() };
    return combineSegments(outbound, returning);
}

int batteryUnitsNeeded(int missionMinutes)
{
    int travelUnits{ missionMinutes / 5 };
    int reserveUnits{ 2 };
    return travelUnits - reserveUnits;
}
