#include <iostream>

int remainingStock(int stock, int shipped)
{
    return stock - shipped;
}

int main()
{
    constexpr int startingStock{ 18 };
    constexpr int shipped{ 5 };
    const int remaining{ remainingStock(startingStock, shipped) };

    std::cout << "Remaining stock: " << remaining << '\n';
    std::cout << "Sample remaining: " << remainingStock(9, 2) << '\n';
    return 0;
}
