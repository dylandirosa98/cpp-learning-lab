#include <iostream>

bool isWithinCapacity(int packages, int capacity)
{
    return packages <= capacity;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Capacity 8 of 10: " << isWithinCapacity(8, 10) << '\n';
    std::cout << "Capacity 10 of 10: " << isWithinCapacity(10, 10) << '\n';
    std::cout << "Capacity 12 of 10: " << isWithinCapacity(12, 10) << '\n';
    return 0;
}
