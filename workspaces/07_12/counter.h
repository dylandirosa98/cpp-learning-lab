/*
Lesson 7.12 - Scope, duration, and linkage summary
LearnCpp: https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/
Tasks:
- Declare the one shared daily-limit object with external linkage.
- Declare the visit-counting function used by main.
Function and object responsibilities:
- g_dailyLimit names the same read-only object in each translation unit.
- visitsToday returns the next count from private persistent function state.
Expected behavior from the complete program:
- The shared limit is 3 and three calls return 1, 2, and 3.
Constraints:
- Keep this header declaration-only and protect it with the unique include guard.
- Do not initialize the shared object or define mutable state in this header.
Completion checklist:
- The constant declaration uses extern and has no initializer.
- Every declaration is inside the include guard.
- The complete target builds warning-free and passes ./course check 7.12.
Run from project root: ./course check 7.12
*/
#ifndef CPP_LEARNING_LAB_CHAPTER7_COUNTER_H
#define CPP_LEARNING_LAB_CHAPTER7_COUNTER_H

// TODO: Give this declaration external linkage without defining the value here.
const int g_dailyLimit{ 1 };
int visitsToday();

#endif
