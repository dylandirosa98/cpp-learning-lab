#include <iostream>

int calibrateReading(int reading)
{
    int offset{3};
    reading -= offset;
    return reading;
}

int main()
{
    int reading{18};
    std::cout << "Raw reading: " << reading << '\n';

    int adjusted{calibrateReading(reading)};
    std::cout << "Adjusted reading: " << adjusted << '\n';
    std::cout << "Raw reading after call: " << reading << '\n';

    return 0;
}
