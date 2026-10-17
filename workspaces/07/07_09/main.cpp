/*
Lesson 7.9 - Inline functions and variables
LearnCpp: https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
Tasks:
- Include points.h and forward declare bonusBadgePoints from bonus.cpp.
- Calculate base points for 3 badges, request bonus points, and add the total.
- Print all three calculated values in the required order.
Constraints:
- Do not duplicate the header definitions or include bonus.cpp.
Exact expected output:
Base badge points: 12
Bonus badge points: 8
Total points: 20
Completion checklist:
- Both translation units use the same guarded inline definitions.
- The C++20 target builds warning-free and passes ./course check 7.9.
*/
#include "points.h"

#include <iostream>

int bonusBadgePoints();

int main() {
    const int basePoints{badgePoints(3)}; // TODO: Call badgePoints.
    const int bonusPoints{bonusBadgePoints()};
    const int totalPoints{basePoints + bonusPoints}; // TODO: Add the results.

    std::cout << "Base badge points: " << basePoints << '\n';
    std::cout << "Bonus badge points: " << bonusPoints << '\n';
    std::cout << "Total points: " << totalPoints << '\n';
    return 0;
}
