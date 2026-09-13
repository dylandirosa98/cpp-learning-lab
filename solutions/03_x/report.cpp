#include "report.h"

#include <iostream>

void printChecks(int combinedMinutes, int batteryUnits)
{
    std::cout << "Check combine(3, 4): " << combinedMinutes << '\n';
    std::cout << "Check battery(10): " << batteryUnits << '\n';
}

void printMission(int outbound, int returning, int total, int batteryUnits)
{
    std::cout << "Courier run: CX-17\n";
    std::cout << "Outbound minutes: " << outbound << '\n';
    std::cout << "Return minutes: " << returning << '\n';
    std::cout << "Total minutes: " << total << '\n';
    std::cout << "Battery units: " << batteryUnits << '\n';
}
