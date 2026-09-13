#include "repair_plan.h"

#include <iostream>

int countRepairUnits(int looseTiles, int crackedTiles)
{
    return looseTiles + crackedTiles;
}

int estimateRepairMinutes(int repairUnits, int minutesPerUnit)
{
    return repairUnits * minutesPerUnit;
}

void printRepairPlan(int repairUnits, int repairMinutes)
{
    std::cout << "Repair units: " << repairUnits << '\n';
    std::cout << "Estimated repair time: " << repairMinutes << " minutes\n";
}
