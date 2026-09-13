#include "sensor_pipeline.h"

#include <iostream>

int main()
{
    int normalized{ normalizeReading(18, 2) };
    int scaled{ scaleReading(normalized, 3) };
    int combined{ combineZones(scaled, 12) };
    int available{ reserveCapacity(combined, 7) };

    std::cout << "Normalized reading: " << normalized << '\n';
    std::cout << "Combined load: " << combined << '\n';
    std::cout << "Available capacity: " << available << '\n';
    return 0;
}
