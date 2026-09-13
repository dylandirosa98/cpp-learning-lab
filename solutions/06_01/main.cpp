#include <iostream>

int main()
{
    constexpr int basePoints{ 10 };
    constexpr int bonusPoints{ 4 };
    constexpr int multiplier{ 3 };
    constexpr int totalPoints{ 100 };
    constexpr int teams{ 4 };
    constexpr int rounds{ 5 };

    const int defaultScore{ basePoints + bonusPoints * multiplier };
    const int groupedScore{ (basePoints + bonusPoints) * multiplier };
    const int pointsPerRound{ totalPoints / teams / rounds };

    std::cout << "Default precedence: " << defaultScore << '\n';
    std::cout << "Parenthesized: " << groupedScore << '\n';
    std::cout << "Left-associated division: " << pointsPerRound << '\n';
    return 0;
}
