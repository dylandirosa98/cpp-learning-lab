#include <iostream>

void checkFlashing()
{
    std::cout << "Flashing secure\n";
}

void checkVent()
{
    std::cout << "Vent clear\n";
}

void inspectRoof()
{
    std::cout << "Roof inspection started\n";
    checkFlashing();
    checkVent();
    std::cout << "Roof inspection complete\n";
}

int main()
{
    std::cout << "Crew dispatched\n";
    inspectRoof();
    std::cout << "Crew returned\n";

    return 0;
}
