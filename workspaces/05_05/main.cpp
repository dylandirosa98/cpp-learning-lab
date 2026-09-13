/*
Lesson 5.5 - Constant expressions
LearnCpp: https://www.learncpp.com/cpp-tutorial/constant-expressions/
Practice:
- Identify which variables are usable in a constant expression.
- Require a compile-time calculation and verify it with static_assert.
Task:
1. Inspect why rows cannot currently participate in capacity's initializer.
2. Make rows a const int while retaining its initializer of 4.
3. Keep seatsPerRow explicitly constexpr and initialized to 6.
4. Keep capacity constexpr and calculate it from the two named variables.
5. Leave static_assert in place so the compiler verifies the invariant.
Function responsibility:
- main declares the dimensions, verifies their product, and reports it.
Constraints:
- Do not replace the capacity expression or output with a hard-coded 24.
- Do not add input or a function call to the compile-time calculation.
Exact expected output:
Capacity: 24 seats
Completion checklist:
- rows is a const integral variable with a constant-expression initializer.
- capacity is constexpr and static_assert validates its calculated value.
- The program builds warning-free as C++20.
Run from project root: ./course check 5.5
*/
#include <iostream>

int main() {
    const int rows{4};
    constexpr int seatsPerRow{6};
    constexpr int capacity{rows * seatsPerRow};
    static_assert(capacity == 24);

    std::cout << "Capacity: " << capacity << " seats\n";
    return 0;
}
