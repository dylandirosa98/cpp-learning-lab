/*
Lesson 7.10 - Sharing global constants across multiple files (using inline variables)
LearnCpp:
https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
Tasks:
- Include time_constants.h so this translation unit sees both constant definitions.
- Return hoursPerWorkday multiplied by minutesPerHour from workdayMinutes.
Concept:
- The same namespaced inline constants can be used here and in main.cpp.
Expected behavior:
- workdayMinutes returns 480 from 8 hours multiplied by 60 minutes.
Constraints:
- Do not duplicate literals or define another copy of either named constant.
Completion checklist:
- The calculation uses both timeConstants-qualified names.
- The complete target passes ./course check 7.10 without warnings.
*/
#include "time_constants.h"

int workdayMinutes() {
    return timeConstants::hoursPerWorkday *
           timeConstants::minutesPerHour; // TODO: Multiply the two shared constants.
}
