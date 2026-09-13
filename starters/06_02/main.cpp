/*
Lesson 6.2 - Arithmetic operators
LearnCpp: https://www.learncpp.com/cpp-tutorial/arithmetic-operators/
Practice:
- Contrast integer division with a deliberately floating-point division.
- Combine binary arithmetic and apply unary minus to a calculated value.
Tasks:
1. Divide totalMinutes by sessions to calculate wholeMinutes.
2. Convert totalMinutes to double before dividing to calculate exactMinutes.
3. Calculate netScore from gains * pointsPerGain - penalty.
4. Initialize reversedScore by applying unary minus to netScore.
Function responsibility:
- main performs and reports the fixed scheduling and scoring calculations.
Constraints:
- Use static_cast<double>; do not change every input to a floating-point type.
- Do not hard-code any calculated result or read input.
Exact expected output:
Whole minutes per session: 38
Exact minutes per session: 38.75
Net score: 3
Reversed score: -3
Completion checklist:
- The integer quotient truncates while the floating quotient retains its fraction.
- The score uses multiplication and subtraction, and its reverse uses unary minus.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 6.2
*/
#include <iostream>

int main()
{
    constexpr int totalMinutes{ 155 };
    constexpr int sessions{ 4 };
    constexpr int gains{ 5 };
    constexpr int pointsPerGain{ 2 };
    constexpr int penalty{ 7 };

    const int wholeMinutes{ totalMinutes + sessions }; // TODO: Use integer division.
    const double exactMinutes{ static_cast<double>(totalMinutes) + sessions }; // TODO: Divide after converting.
    const int netScore{ gains + pointsPerGain - penalty }; // TODO: Multiply gains by pointsPerGain.
    const int reversedScore{ netScore }; // TODO: Apply unary minus to netScore.

    std::cout << "Whole minutes per session: " << wholeMinutes << '\n';
    std::cout << "Exact minutes per session: " << exactMinutes << '\n';
    std::cout << "Net score: " << netScore << '\n';
    std::cout << "Reversed score: " << reversedScore << '\n';
    return 0;
}
