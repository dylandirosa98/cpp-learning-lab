/*
Lesson 4.7 - Introduction to scientific notation
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-scientific-notation/
Practice:
- Read a C++ e-notation literal as a significand multiplied by a power of ten.
- Preserve significant digits while correcting positive and negative exponents.
Task:
1. Keep probeDistanceKm and pulseDurationSeconds as double variables.
2. Correct only the exponent in each initializer.
3. The distance must represent 1.496 times 10 to the eighth kilometers.
4. The duration must represent 2.500 times 10 to the negative third seconds.
5. Keep both setprecision calls so decimal rendering is deterministic.
Constraints:
- Do not use input, decimal replacement constants, or hard-coded result strings.
- Keep the significands 1.496 and 2.500 exactly as written.
Exact expected output:
Probe distance: 149600000 km
Pulse duration: 0.002500 s
Completion checklist:
- The large value uses a positive exponent and the small value a negative one.
- Both labels, units, spacing, and decimal places match exactly.
- The program builds warning-free as C++20.
Run from project root: ./course check 4.7
*/
#include <iomanip>
#include <iostream>

int main()
{
    double probeDistanceKm{ 1.496e7 };
    double pulseDurationSeconds{ 2.500e3 };

    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Probe distance: " << probeDistanceKm << " km\n";
    std::cout << std::setprecision(6);
    std::cout << "Pulse duration: " << pulseDurationSeconds << " s\n";
    return 0;
}
