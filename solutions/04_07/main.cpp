#include <iomanip>
#include <iostream>

int main()
{
    double probeDistanceKm{ 1.496e8 };
    double pulseDurationSeconds{ 2.500e-3 };

    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Probe distance: " << probeDistanceKm << " km\n";
    std::cout << std::setprecision(6);
    std::cout << "Pulse duration: " << pulseDurationSeconds << " s\n";
    return 0;
}
