/*
Lesson 6.7 - Relational operators and floating point comparisons
LearnCpp: https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
Practice:
- Contrast exact floating-point equality with a tolerance-based comparison.
- Scale relative tolerance while retaining an absolute tolerance near zero.
Tasks:
1. Calculate the absolute difference between a and b.
2. Find the larger absolute operand magnitude with std::max.
3. Compare difference with the greater absolute-or-relative tolerance.
4. Print exact, approximate, and clearly separated comparison results.
Function responsibilities:
- approximatelyEqualRelAbs implements reusable comparison policy without output.
- main supplies fixed values and reports three relational results.
Constraints:
- Keep all parameters double and use both relEpsilon and absEpsilon.
- Do not force the expected booleans or read stdin.
Exact expected output:
Exactly equal: false
Approximately equal: true
Clearly separated: false
Completion checklist:
- The comparison uses std::abs for differences and magnitudes.
- The allowed error is max(absEpsilon, relEpsilon * largestMagnitude).
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 6.7
*/
#include <algorithm>
#include <cmath>
#include <iostream>

bool approximatelyEqualRelAbs(double a, double b, double relEpsilon, double absEpsilon)
{
    const double difference{ std::abs(a - b) };
    const double largestMagnitude{ std::max(std::abs(a), std::abs(b)) };
    return difference <= std::max(absEpsilon, relEpsilon * largestMagnitude);
}

int main()
{
    constexpr double target{ 0.3 };
    constexpr double relEpsilon{ 1e-12 };
    constexpr double absEpsilon{ 1e-12 };
    const double sum{ 0.1 + 0.2 };

    std::cout << std::boolalpha;
    std::cout << "Exactly equal: " << (sum == target) << '\n';
    std::cout << "Approximately equal: " << approximatelyEqualRelAbs(sum, target, relEpsilon, absEpsilon) << '\n';
    std::cout << "Clearly separated: " << approximatelyEqualRelAbs(sum, 0.31, relEpsilon, absEpsilon) << '\n';
    return 0;
}
