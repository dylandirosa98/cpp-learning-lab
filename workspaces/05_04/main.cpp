/*
Lesson 5.4 - The as-if rule and compile-time optimization
LearnCpp: https://www.learncpp.com/cpp-tutorial/the-as-if-rule-and-compile-time-optimization/
Practice:
- Write readable constant calculations and preserve observable behavior.
- Let the compiler choose valid optimizations instead of probing for them.
Task:
1. Compute bakedMuffins by multiplying trays, rowsPerTray, and muffinsPerRow.
2. Compute reservedMuffins as two rows times muffinsPerRow.
3. Compute packedMuffins by subtracting reservedMuffins from bakedMuffins.
4. Keep both output lines identical in debug and release configurations.
Function responsibility:
- main names the bakery dimensions, derives fixed totals, and prints observable results.
Constraints:
- Keep the values const and express relationships with their descriptive names.
- Do not inspect assembly, time the expression, use volatile, or branch on build macros.
Exact expected output:
Baked muffins: 72
Packed muffins: 60
Completion checklist:
- The calculations reveal how each result is derived.
- Correctness depends only on exact observable output, not a specific optimization.
- The program builds warning-free as C++20.
Run from project root: ./course check 5.4
*/
#include <iostream>

int main() {
    const int trays{3};
    const int rowsPerTray{4};
    const int muffinsPerRow{6};
    const int bakedMuffins{trays * rowsPerTray * muffinsPerRow};
    const int reservedMuffins{2 * muffinsPerRow};
    const int packedMuffins{bakedMuffins - reservedMuffins};

    std::cout << "Baked muffins: " << bakedMuffins << '\n';
    std::cout << "Packed muffins: " << packedMuffins << '\n';
    return 0;
}
