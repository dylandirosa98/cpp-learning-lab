#include "repair_plan.h"

int main()
{
    int looseTiles{ 4 };
    int crackedTiles{ 3 };
    int repairUnits{ countRepairUnits(looseTiles, crackedTiles) };
    int repairMinutes{ estimateRepairMinutes(repairUnits, 15) };

    printRepairPlan(repairUnits, repairMinutes);
    return 0;
}
