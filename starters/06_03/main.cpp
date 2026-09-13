/*
Lesson 6.3 - Remainder and exponentiation
LearnCpp: https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
Practice:
- Use integer remainder for wrapping and divisibility.
- Use std::pow for exponentiation because ^ is not a power operator.
Tasks:
1. Wrap startDay + dayOffset into a seven-day cycle with %.
2. Test whether shipmentCount has remainder zero after division by 2.
3. Calculate base raised to exponent with std::pow.
4. Enable std::boolalpha and print the supplied report.
Function responsibility:
- main calculates three fixed demonstrations and reports their results.
Constraints:
- Include <cmath>, do not use ^, and do not hard-code the answers.
- Keep the exercise deterministic and do not read stdin.
Exact expected output:
Wrapped weekday index: 2
Shipment is even: true
2 to the power 5: 32
Completion checklist:
- Both remainder expressions use integral operands.
- Exponentiation calls std::pow and boolean output is alphabetic.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 6.3
*/
#include <cmath>
#include <iostream>

int main()
{
    constexpr int startDay{ 5 };
    constexpr int dayOffset{ 4 };
    constexpr int daysPerWeek{ 7 };
    constexpr int shipmentCount{ 18 };
    constexpr int base{ 2 };
    constexpr int exponent{ 5 };

    const int wrappedDay{ startDay + dayOffset + daysPerWeek }; // TODO: Wrap the sum with remainder.
    const bool shipmentIsEven{ shipmentCount == 2 }; // TODO: Test the remainder after division by 2.
    const double power{ base * exponent }; // TODO: Call std::pow.

    std::cout << std::boolalpha;
    std::cout << "Wrapped weekday index: " << wrappedDay << '\n';
    std::cout << "Shipment is even: " << shipmentIsEven << '\n';
    std::cout << "2 to the power 5: " << power << '\n';
    return 0;
}
