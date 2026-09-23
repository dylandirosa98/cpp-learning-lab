/*
Lesson 5.2 - Literals
LearnCpp: https://www.learncpp.com/cpp-tutorial/literals/
Practice:
- Use suffixes to give literals the intended types.
- Replace domain-specific magic values with descriptive constants.
Task:
1. Change litersPerCan to const float and give 1.5 the f suffix.
2. Change cansPerCase to const unsigned int and give 8 the u suffix.
3. Change annualCapacity to const long long and write its initializer as 1'000'000LL.
4. Make litersPerCase a const float calculated from the two named per-case values.
5. Preserve fixed one-decimal formatting and both report lines.
Function responsibility:
- main defines typed business literals, calculates one case volume, and prints the report.
Constraints:
- Use the f, u, and uppercase LL suffixes in the requested declarations.
- Do not repeat 1.5 or 8 in the calculation and do not hard-code 12.0.
Exact expected output:
Case volume: 12.0 liters
Annual capacity: 1000000 cans
Completion checklist:
- Each literal suffix agrees with the variable type.
- The calculation contains named values rather than magic values.
- The program builds warning-free as C++20.
Run from project root: ./course check 5.2
*/
#include <iomanip>
#include <iostream>

int main() {
    const float litersPerCan{1.5f};
    const unsigned int cansPerCase{8u};
    const long long annualCapacity{1'000'000LL};
    const float litersPerCase{litersPerCan * cansPerCase};

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Case volume: " << litersPerCase << " liters\n";
    std::cout << "Annual capacity: " << annualCapacity << " cans\n";
    return 0;
}
