#include "route.h"

int combineSegments(int firstMinutes, int secondMinutes)
{
    return firstMinutes + secondMinutes;
}

int outboundMinutes()
{
    return combineSegments(12, 8);
}

int returnMinutes()
{
    return combineSegments(9, 6);
}

int missionMinutes()
{
    int outbound{ outboundMinutes() };
    int returning{ returnMinutes() };
    return combineSegments(outbound, returning);
}

int batteryUnitsNeeded(int missionMinutes)
{
    int travelUnits{ missionMinutes / 5 };
    int reserveUnits{ 2 };
    return travelUnits + reserveUnits;
}
