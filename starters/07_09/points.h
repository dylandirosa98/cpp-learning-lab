/*
Lesson 7.9 - Inline functions and variables
LearnCpp: https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
Tasks:
- Define inline constexpr int pointsPerBadge as 4 inside this guarded header.
- Define inline int badgePoints(int badges) and return badges * pointsPerBadge.
Concept:
- Including one identical inline definition in multiple translation units is ODR-safe.
Expected behavior:
- badgePoints(3) returns 12 and badgePoints(2) returns 8.
Constraints:
- Keep both full definitions in this header and do not use static or stream output.
Completion checklist:
- The include guard encloses both inline definitions.
- main.cpp and bonus.cpp can both use badgePoints and pass ./course check 7.9.
*/
#ifndef CPP_LEARNING_LAB_POINTS_H
#define CPP_LEARNING_LAB_POINTS_H

inline constexpr int pointsPerBadge{ 0 }; // TODO: Initialize this inline variable to 4.

inline int badgePoints(int badges)
{
    return badges; // TODO: Multiply by pointsPerBadge.
}

#endif
