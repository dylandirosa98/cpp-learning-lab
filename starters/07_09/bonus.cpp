/*
Lesson 7.9 - Inline functions and variables
LearnCpp: https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
Tasks:
- Include points.h so this translation unit sees the complete inline definitions.
- Implement bonusBadgePoints by returning badgePoints for 2 badges.
Concept:
- The linker can consolidate the matching inline definitions included here and in main.
Expected behavior:
- bonusBadgePoints returns 8 for the complete program's bonus line.
Constraints:
- Do not repeat pointsPerBadge or badgePoints in this source file.
Completion checklist:
- bonusBadgePoints returns badgePoints(2).
- The complete target passes ./course check 7.9.
*/
#include "points.h"

int bonusBadgePoints()
{
    return 0; // TODO: Return the points for 2 badges.
}
