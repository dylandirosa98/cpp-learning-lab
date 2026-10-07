/*
Lesson 7.6 - Internal linkage
LearnCpp: https://www.learncpp.com/cpp-tutorial/internal-linkage/
Tasks:
- Give this file a namespace-scope static int g_offset initialized to 2.
- Forward declare sensorReading, calculate 10 + this file's offset, and print both readings.
Concept:
- main.cpp's g_offset is independent of the identically named variable in sensor.cpp.
Constraints:
- Do not include sensor.cpp or try to access sensor.cpp's internal names directly.
Exact expected output:
Main reading: 12
Sensor reading: 15
Completion checklist:
- g_offset has internal linkage and sensorReading(10) links from the other source file.
- The C++20 program builds warning-free and passes ./course check 7.6.
*/
#include <iostream>

static int g_offset{2}; // TODO: Initialize this internal variable correctly.

int sensorReading(int reading);

int main() {
    const int mainReading{10 + g_offset};
    std::cout << "Main reading: " << mainReading << '\n';
    std::cout << "Sensor reading: " << sensorReading(10) << '\n';
    return 0;
}
