/*
Lesson 3.5 - More debugging tactics
LearnCpp: https://www.learncpp.com/cpp-tutorial/more-debugging-tactics/
What is practiced:
- Use centrally controlled reusable logs to locate bad runtime state, repair
  the production pipeline, and disable diagnostics without deleting them.
Explicit expected behavior:
- Two water events contribute six points and one electrical event contributes
  five points, for alert score 11.
- Four response minutes per alert point produce a 44-minute response window.
Debugging procedure:
1. Run this untouched program while diagnostics.h enables LAB_LOG.
2. Keep the two-line stdout report distinct from std::clog diagnostic events.
3. Confirm the alert score first, then inspect response-stage inputs and result.
4. Identify and explain the first disagreement before editing production code.
5. Repair only the responsible behavior and rerun with logs enabled once.
6. Disable the single central definition, preserve LAB_LOG calls, and check.
File and function responsibilities:
- main supplies fixed event counts, coordinates both calculations, and owns
  the two required normal output lines.
- inspection_alert.h declares calculations defined in inspection_alert.cpp.
- diagnostics.h centrally controls reusable diagnostics in the module.
Constraints:
- Preserve fixed event counts, stored stage results, and output labels.
- Do not hard-code expected results or print diagnostic text with std::cout.
- Include headers rather than implementation files.
- Use explicit std:: qualification and no using namespace std.
Exact expected output:
System alert score: 11
Response window: 44 minutes
Completion checklist:
- Diagnostic and normal streams were interpreted separately.
- Logged stage values identify the first incorrect runtime state.
- The production repair is minimal and diagnostics are centrally disabled.
- The warning-free final run produces exactly the expected stdout.
Run from project root: ./course check 3.5
*/
#include "inspection_alert.h"

#include <iostream>

int main()
{
    int alertScore{ calculateAlertScore(2, 1) };
    int responseMinutes{ calculateResponseMinutes(alertScore, 4) };

    std::cout << "System alert score: " << alertScore << '\n';
    std::cout << "Response window: " << responseMinutes << " minutes\n";
    return 0;
}
