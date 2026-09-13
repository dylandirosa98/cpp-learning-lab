#include <algorithm>
#include <cmath>
#include <iostream>

bool approximatelyEqualRelAbs(double a, double b, double relEpsilon, double absEpsilon)
{
    const double difference{ std::abs(a - b) };
    const double largestMagnitude{ std::max(std::abs(a), std::abs(b)) };
    return difference <= std::max(absEpsilon, relEpsilon * largestMagnitude);
}

int main()
{
    constexpr double target{ 0.3 };
    constexpr double relEpsilon{ 1e-12 };
    constexpr double absEpsilon{ 1e-12 };
    const double sum{ 0.1 + 0.2 };

    std::cout << std::boolalpha;
    std::cout << "Exactly equal: " << (sum == target) << '\n';
    std::cout << "Approximately equal: " << approximatelyEqualRelAbs(sum, target, relEpsilon, absEpsilon) << '\n';
    std::cout << "Clearly separated: " << approximatelyEqualRelAbs(sum, 0.31, relEpsilon, absEpsilon) << '\n';
    return 0;
}
