#include <iostream>

int main()
{
    constexpr double unitCost{ 2.5 };
    constexpr int packageCount{ 4 };
    constexpr double totalCost{ unitCost * packageCount };
    static_assert(totalCost == 10.0);

    int currentVisitors{ 18 };
    const int snapshotVisitors{ currentVisitors };

    std::cout << "Unit cost: " << unitCost << '\n';
    std::cout << "Total cost: " << totalCost << '\n';
    std::cout << "Visitor snapshot: " << snapshotVisitors << '\n';
    return 0;
}
