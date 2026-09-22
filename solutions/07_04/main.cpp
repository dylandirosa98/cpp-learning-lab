#include <iostream>

namespace Warehouse
{
    constexpr int capacity{ 40 };
}

int availableSpace(int stored)
{
    return Warehouse::capacity - stored;
}

int main()
{
    constexpr int stored{ 27 };

    std::cout << "Warehouse capacity: " << Warehouse::capacity << '\n';
    std::cout << "Items stored: " << stored << '\n';
    std::cout << "Available space: " << availableSpace(stored) << '\n';
    return 0;
}
