/*
Lesson 3.5 - More debugging tactics
LearnCpp: https://www.learncpp.com/cpp-tutorial/more-debugging-tactics/
What is practiced:
- Diagnose a staged calculation with conditionally compiled logging, then
  disable diagnostics centrally without removing reusable log statements.
Explicit expected behavior:
- Two water events at three points and one electrical event at five points
  produce alert score 11.
- Alert score 11 at four minutes per point produces 44 response minutes.
Debugging procedure:
1. Run the untouched starter while diagnostics are enabled.
2. Distinguish LAB_LOG messages on std::clog from the normal stdout report.
3. Compare each logged argument and result with the contracts above.
4. Locate and explain the earliest mismatch before changing production code.
5. Repair that behavior, then disable the central diagnostics definition.
6. Preserve LAB_LOG calls and verify exact output with the checker.
File and function responsibilities:
- This guarded header declares both alert calculation functions only.
- inspection_alert.cpp owns definitions and conditional log events.
- diagnostics.h defines LAB_LOG and its single central switch.
- main.cpp coordinates fixed inputs and normal output.
Constraints:
- Keep this header free of function bodies and implementation includes.
- Preserve both declarations and their matching definitions.
- Use explicit std:: qualification and no using namespace std.
Exact expected output:
System alert score: 11
Response window: 44 minutes
Completion checklist:
- Logged runtime state, not domain guessing, identified the discrepancy.
- Both function contracts remain represented by their declarations.
- Diagnostics are centrally disabled but instrumentation remains available.
- The final program compiles without warnings and prints exactly two lines.
Run from project root: ./course check 3.5
*/
#ifndef CPP_LEARNING_LAB_INSPECTION_ALERT_H
#define CPP_LEARNING_LAB_INSPECTION_ALERT_H

int calculateAlertScore(int waterEvents, int electricalEvents);
int calculateResponseMinutes(int alertScore, int minutesPerPoint);

#endif
