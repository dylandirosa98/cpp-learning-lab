#include <iostream>

int main()
{
    bool systemOnline{ true };
    char zoneCode{ 'C' };
    double targetVoltage{ 12.5 };

    std::cout << std::boolalpha;
    std::cout << "System online: " << systemOnline << '\n';
    std::cout << "Zone code: " << zoneCode << '\n';
    std::cout << "Target voltage: " << targetVoltage << '\n';
    return 0;
}
