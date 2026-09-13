#include <iostream>

int calculateSealCount(int containers, int sealsPerContainer)
{
    return containers * sealsPerContainer;
}

void runSelfChecks()
{
    std::cout << "Self-check 2 x 5: " << calculateSealCount(2, 5) << '\n';
    std::cout << "Self-check 0 x 6: " << calculateSealCount(0, 6) << '\n';
}

void printShipmentReport(int sealCount)
{
    std::cout << "Shipment seals: " << sealCount << '\n';
}

int main()
{
    runSelfChecks();
    printShipmentReport(calculateSealCount(4, 7));
    return 0;
}
