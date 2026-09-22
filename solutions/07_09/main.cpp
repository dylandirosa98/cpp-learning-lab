#include "points.h"

#include <iostream>

int bonusBadgePoints();

int main()
{
    const int basePoints{ badgePoints(3) };
    const int bonusPoints{ bonusBadgePoints() };
    const int totalPoints{ basePoints + bonusPoints };

    std::cout << "Base badge points: " << basePoints << '\n';
    std::cout << "Bonus badge points: " << bonusPoints << '\n';
    std::cout << "Total points: " << totalPoints << '\n';
    return 0;
}
