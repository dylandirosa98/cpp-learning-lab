#include "report.h"

#include <iostream>

namespace Report
{
    void printHeading(int targetSamples)
    {
        std::cout << "Field survey\n";
        std::cout << "Target samples: " << targetSamples << '\n';
    }

    void printSample(int id, int rawReading, int calibratedReading)
    {
        std::cout << "Sample " << id << ": raw " << rawReading
                  << ", calibrated " << calibratedReading << '\n';
    }

    void printSummary(int legacyFirst, int defaultFirst, int average)
    {
        std::cout << "Legacy first reading: " << legacyFirst << '\n';
        std::cout << "Default first reading: " << defaultFirst << '\n';
        std::cout << "Average calibrated: " << average << '\n';
    }
}
