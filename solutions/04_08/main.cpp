#include <iomanip>
#include <iostream>

double averageTemperature(double morning, double afternoon)
{
    return (morning + afternoon) / 2.0;
}

int main()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average temperature: " << averageTemperature(18.5, 24.0) << " C\n";
    return 0;
}
