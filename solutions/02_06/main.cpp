#include <iostream>

int calculateRoofArea(int length, int width)
{
    return length * width;
}

int calculateRunoffUnits(int area, int rainfallUnits)
{
    return area * rainfallUnits;
}

void printDrainageReport(int area, int runoffUnits)
{
    std::cout << "Roof area: " << area << " square units\n";
    std::cout << "Runoff load: " << runoffUnits << " units\n";
}

int main()
{
    int area{calculateRoofArea(12, 8)};
    int runoffUnits{calculateRunoffUnits(area, 3)};
    printDrainageReport(area, runoffUnits);

    return 0;
}
