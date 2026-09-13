#include "inspection.h"
#include "report.h"

int main()
{
    int riskPoints{ calculateRiskPoints(5, 4) };
    int crewHours{ estimateCrewHours(riskPoints) };
    printInspection(riskPoints, crewHours);
    return 0;
}
