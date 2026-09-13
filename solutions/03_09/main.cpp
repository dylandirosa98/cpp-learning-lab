#include <iostream>

int applySensorOffset(int rawReading)
{
    return rawReading + 3;
}

int sampleIntake()
{
    return applySensorOffset(12);
}

int sampleOutlet()
{
    return applySensorOffset(8);
}

int ventilationDifference()
{
    int intake{ sampleIntake() };
    int outlet{ sampleOutlet() };
    return intake - outlet;
}

int main()
{
    std::cout << "Ventilation difference: " << ventilationDifference() << '\n';
    return 0;
}
