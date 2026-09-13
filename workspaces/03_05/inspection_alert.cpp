/*
Lesson 3.5 - More debugging tactics
LearnCpp: https://www.learncpp.com/cpp-tutorial/more-debugging-tactics/
What is practiced:
- Read reusable std::clog diagnostics controlled by a shared preprocessor
  switch, repair production behavior, and retain disabled instrumentation.
Explicit expected behavior:
- calculateAlertScore receives water count 2 and electrical count 1 and
  produces score 11 from weights three and five.
- calculateResponseMinutes receives score 11 and four minutes per point and
  produces 44 minutes.
Debugging procedure:
1. Run the untouched executable with ENABLE_DIAGNOSTICS active.
2. Read LAB_LOG events in execution order separately from normal output.
3. Compare each function's logged parameters and result with the values above.
4. Stop at the first mismatch and determine whether it began before or inside
   that function before editing any production statement.
5. Repair the responsible behavior and rerun once with logs still enabled.
6. Disable the central switch, retain these LAB_LOG calls, and check stdout.
File and function responsibilities:
- This file includes its own interface first, then diagnostics.h.
- calculateAlertScore and calculateResponseMinutes own arithmetic and log their
  received state and calculated results.
- main.cpp owns normal report output and pipeline coordination.
Constraints:
- Keep calculations deterministic and use only the function parameters.
- Keep diagnostic output in LAB_LOG and normal output out of this module.
- Do not define the diagnostic switch here or use using namespace std.
Exact expected output:
System alert score: 11
Response window: 44 minutes
Completion checklist:
- Logs were compared stage by stage with explicit expected state.
- The earliest mismatch can be explained from observed values.
- LAB_LOG calls remain after the central switch is disabled.
- The final build has no warnings and normal stdout matches exactly.
Run from project root: ./course check 3.5
*/
#include "inspection_alert.h"

#include "diagnostics.h"

int calculateAlertScore(int waterEvents, int electricalEvents)
{
    LAB_LOG("calculateAlertScore inputs: water=" << waterEvents
                                                 << ", electrical=" << electricalEvents);
    int alertScore{ waterEvents * 3 + electricalEvents * 5 };
    LAB_LOG("calculateAlertScore result: " << alertScore);
    return alertScore;
}

int calculateResponseMinutes(int alertScore, int minutesPerPoint)
{
    LAB_LOG("calculateResponseMinutes inputs: score=" << alertScore
                        << ", minutesPerPoint=" << minutesPerPoint);
    int responseMinutes{ alertScore * minutesPerPoint };
    LAB_LOG("calculateResponseMinutes result: " << responseMinutes);
    return responseMinutes;
}
