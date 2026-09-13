#include "inspection.h"

int calculateRiskPoints(int moistureReadings, int damagedTiles)
{
    return moistureReadings * 3 + damagedTiles * 2;
}

int estimateCrewHours(int riskPoints)
{
    return riskPoints / 4;
}
