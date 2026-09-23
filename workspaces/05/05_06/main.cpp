/*
Lesson 5.6 - Constexpr variables
LearnCpp: https://www.learncpp.com/cpp-tutorial/constexpr-variables/
Practice:
- Use constexpr for variables whose initializers are known at compile time.
- Use const for a runtime value that must not change after initialization.
Task:
1. Repair the three compile-time declarations used by static_assert.
2. Keep totalCost calculated as unitCost * packageCount.
3. Do not change currentVisitors from a mutable int.
4. Keep snapshotVisitors const because it captures a runtime value.
5. Preserve all three calculated report lines and their order.
Function responsibility:
- main contrasts compile-time variables with one runtime constant snapshot.
Constraints:
- Focus on constexpr variables; do not add or define constexpr functions.
- Do not hard-code totalCost or the printed results.
Exact expected output:
Unit cost: 2.5
Total cost: 10
Visitor snapshot: 18
Completion checklist:
- All three compile-time values are declared constexpr.
- The runtime-derived snapshot remains const rather than constexpr.
- static_assert compiles and the program is warning-free as C++20.
Run from project root: ./course check 5.6
*/
#include <iostream>

int main() {
    constexpr double unitCost{2.5};
    constexpr int packageCount{4};
    constexpr double totalCost{unitCost * packageCount};
    static_assert(totalCost == 10.0);

    int currentVisitors{18};
    const int snapshotVisitors{currentVisitors};

    std::cout << "Unit cost: " << unitCost << '\n';
    std::cout << "Total cost: " << totalCost << '\n';
    std::cout << "Visitor snapshot: " << snapshotVisitors << '\n';
    return 0;
}
