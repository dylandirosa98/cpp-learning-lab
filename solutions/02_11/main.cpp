#include "roof_math.h"

#include <iostream>

int main()
{
    int areaPerPanel{ panelArea(12, 10) };
    std::cout << "Roof coverage: " << totalArea(areaPerPanel, 4) << " sq ft\n";
    return 0;
}
