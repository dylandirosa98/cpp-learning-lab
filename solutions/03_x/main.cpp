#include "report.h"
#include "route.h"

int main()
{
    int combinedCheck{ combineSegments(3, 4) };
    int batteryCheck{ batteryUnitsNeeded(10) };
    printChecks(combinedCheck, batteryCheck);

    int outbound{ outboundMinutes() };
    int returning{ returnMinutes() };
    int total{ missionMinutes() };
    int batteryUnits{ batteryUnitsNeeded(total) };
    printMission(outbound, returning, total, batteryUnits);
    return 0;
}
