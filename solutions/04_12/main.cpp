#include <iomanip>
#include <iostream>

double averagePerTeam(int items, int teams)
{
    return static_cast<double>(items) / teams;
}

int main()
{
    double crates{ 7.75 };
    int wholeCrates{ static_cast<int>(crates) };

    std::cout << "Whole crates: " << wholeCrates << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Average per team: " << averagePerTeam(7, 2) << '\n';
    return 0;
}
