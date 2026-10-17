/*
Lesson 7.10 - Sharing global constants across multiple files (using inline variables)
LearnCpp:
https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
Tasks:
- Inside namespace timeConstants, define inline constexpr int minutesPerHour as 60.
- Define inline constexpr int hoursPerWorkday as 8 beside it.
Concept:
- Header-defined inline constexpr constants are shared and remain constant expressions.
Expected behavior:
- The constants support compile-time results of 90 meeting minutes and 480 workday minutes.
Constraints:
- Keep the definitions in the include guard; do not use extern, static, or pragma once.
Completion checklist:
- Both names are namespace-qualified, inline, constexpr, and initialized exactly once here.
- Both source files can include this header and pass ./course check 7.10.
*/
#ifndef CPP_LEARNING_LAB_TIME_CONSTANTS_H
#define CPP_LEARNING_LAB_TIME_CONSTANTS_H

namespace timeConstants {
inline constexpr int minutesPerHour{60}; // TODO: Make inline and initialize to 60.
inline constexpr int hoursPerWorkday{8}; // TODO: Make inline and initialize to 8.
} // namespace timeConstants

#endif
