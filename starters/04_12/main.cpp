/*
Lesson 4.12 - Introduction to type conversion and static_cast
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
Practice:
- Make intentional conversions visible with static_cast<target_type>.
- Convert before integer division loses a fractional result.
Task:
1. Keep static_cast<int>(crates); truncation is intentional for whole crates.
2. Inspect when division occurs in averagePerTeam's current expression.
3. Move the double conversion so it applies to items before division.
4. Keep teams as the divisor and retain the supplied call with 7 and 2.
5. Preserve fixed one-decimal formatting for stable output.
Function responsibility:
- averagePerTeam computes a fractional quotient from integer counts.
- main demonstrates intentional truncation and prints both results.
Constraints:
- Use static_cast<int> and static_cast<double>; do not use a C-style cast.
- Do not hard-code 7 or 3.5 as calculated result variables.
Exact expected output:
Whole crates: 7
Average per team: 3.5
Completion checklist:
- The truncating cast is deliberate and the division cast occurs first.
- The average retains its half-item fraction.
- The program builds warning-free as C++20.
Run from project root: ./course check 4.12
*/
#include <iomanip>
#include <iostream>

double averagePerTeam(int items, int teams)
{
    return static_cast<double>(items / teams);
}

int main()
{
    double crates{ 7.75 };
    int wholeCrates{ static_cast<int>(crates) };

    std::cout << "Whole crates: " << wholeCrates << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Average per team: " << averagePerTeam(7, 2) << '\n';
    return 0;
}
