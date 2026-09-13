#include <iostream>

int main()
{
    constexpr int totalMinutes{ 155 };
    constexpr int sessions{ 4 };
    constexpr int gains{ 5 };
    constexpr int pointsPerGain{ 2 };
    constexpr int penalty{ 7 };

    const int wholeMinutes{ totalMinutes / sessions };
    const double exactMinutes{ static_cast<double>(totalMinutes) / sessions };
    const int netScore{ gains * pointsPerGain - penalty };
    const int reversedScore{ -netScore };

    std::cout << "Whole minutes per session: " << wholeMinutes << '\n';
    std::cout << "Exact minutes per session: " << exactMinutes << '\n';
    std::cout << "Net score: " << netScore << '\n';
    std::cout << "Reversed score: " << reversedScore << '\n';
    return 0;
}
