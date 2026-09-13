#include <iostream>

int installedFasteners(int rows, int fastenersPerRow)
{
    return rows * fastenersPerRow;
}

void printInventory(int installed, int spare)
{
    std::cout << "Installed fasteners: " << installed << '\n';
    std::cout << "Fasteners available: " << installed + spare << '\n';
}

int main()
{
    int installed{ installedFasteners(6, 8) };
    int spare{ 5 };
    printInventory(installed, spare);
    return 0;
}
