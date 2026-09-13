#include "roof_metrics.h"
#include "inspection_report.h"

#include <iostream>

int main()
{
    printAnchorChecks(requiredAnchorChecks(6));
    return 0;
}

int requiredAnchorChecks(int roofSections)
{
    return roofSections * 2;
}

void printAnchorChecks(int checks)
{
    std::cout << "Required anchor checks: " << checks << '\n';
}
