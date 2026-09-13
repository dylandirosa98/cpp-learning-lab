#include <iostream>

void printTemperatureState(int temperature)
{
    std::cout << "Temperature " << temperature << ": ";
    if (temperature < 0)
        std::cout << "below freezing\n";
    else if (temperature > 0)
        std::cout << "above freezing\n";
    else
        std::cout << "freezing point\n";
}

int main()
{
    printTemperatureState(-4);
    printTemperatureState(0);
    printTemperatureState(7);
    return 0;
}
