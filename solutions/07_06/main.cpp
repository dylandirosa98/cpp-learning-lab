#include <iostream>

static int g_offset{ 2 };

int sensorReading(int reading);

int main()
{
    const int mainReading{ 10 + g_offset };
    std::cout << "Main reading: " << mainReading << '\n';
    std::cout << "Sensor reading: " << sensorReading(10) << '\n';
    return 0;
}
