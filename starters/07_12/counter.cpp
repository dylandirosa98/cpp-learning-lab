/*
Lesson 7.12 - Scope, duration, and linkage summary
LearnCpp: https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/
Tasks:
- Define the externally linked daily limit once with the value 3.
- Retain and increment a private local count across visitsToday calls.
Function and object responsibilities:
- g_dailyLimit supplies the single shared limit declared by counter.h.
- visitsToday owns a block-scoped counter with static duration.
Expected behavior from the complete program:
- Successive calls return 1, then 2, then 3 rather than restarting.
Constraints:
- Include counter.h first and perform no stream input or output here.
- Do not move the persistent counter to namespace scope.
Completion checklist:
- The external const definition appears exactly once in this source file.
- The static local is initialized to zero, incremented, and returned.
- The complete target builds warning-free and passes ./course check 7.12.
Run from project root: ./course check 7.12
*/
#include "counter.h"

// TODO: Provide the single external definition initialized to 3.

int visitsToday()
{
    // TODO: Make this count persist, increment it, and return the new value.
    int visits{ 0 };
    return visits;
}
