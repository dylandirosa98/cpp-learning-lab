/*
Lesson 2.10 - Introduction to the preprocessor
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/

What you are practicing:
- Defining a feature macro and conditionally compiling source lines.
- Keeping an inactive feature's code out of the translation unit.

Required file and observable behavior:
- main.cpp defines ROOF_DIAGNOSTICS without replacement text before main().
- main() always prints the inspection status.
- A ROOF_DIAGNOSTICS conditional includes the sensor-bus line.
- A separate LEGACY_SENSOR conditional excludes the legacy-sensor line.

Feature conditions:
- ROOF_DIAGNOSTICS is defined, so its conditional output must be compiled.
- LEGACY_SENSOR remains undefined, so its conditional output must not be
  compiled or printed.

Constraints:
- Use matching #ifdef and #endif directives for each feature.
- Do not define LEGACY_SENSOR, and do not add semicolons to directives.
- Qualify standard-library names explicitly with std::, including std::cout;
  do not use a using-directive.

Expected output:
Inspection status: ready
Diagnostics: sensor bus online

Completion checklist:
- The status line remains unconditional.
- Each diagnostic line is guarded by its matching feature macro.
- Only the two expected lines are printed, in the shown order.

Checker command: ./course check 2.10
*/
#include <iostream>

#define ROOF_DIAGNOSTICS

int main()
{
    std::cout << "Inspection status: ready\n";

    // TODO: Guard each diagnostic with its own matching feature condition.
    std::cout << "Diagnostics: sensor bus online\n";
    std::cout << "Diagnostics: legacy sensor enabled\n";

    return 0;
}
