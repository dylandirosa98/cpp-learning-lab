/*
Lesson 5.1 - Constant variables (named constants)
LearnCpp: https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
Practice:
- Mark values that cannot change with const.
- Calculate with descriptive names instead of repeated literals.
Task:
1. Make cartonsPerShelf and shelfCount const int variables.
2. Make totalCartons a const int because it is not reassigned.
3. Replace the repeated 6 in the total calculation with cartonsPerShelf.
4. Keep all three report lines and their current order.
Function responsibility:
- main defines the fixed shelf configuration, calculates its total, and reports it.
Constraints:
- Put const before the type and initialize every constant at its definition.
- Do not use #define, add input, or hard-code the calculated total.
Exact expected output:
Cartons per shelf: 6
Shelf count: 5
Total cartons: 30
Completion checklist:
- All three fixed values are const and have descriptive names.
- The total expression uses both named constants.
- The program builds warning-free as C++20.
Run from project root: ./course check 5.1
*/
#include <iostream>

int main() {
    const int cartonsPerShelf{6};
    const int shelfCount{5};
    const int totalCartons{cartonsPerShelf * shelfCount};

    std::cout << "Cartons per shelf: " << cartonsPerShelf << '\n';
    std::cout << "Shelf count: " << shelfCount << '\n';
    std::cout << "Total cartons: " << totalCartons << '\n';
    return 0;
}
