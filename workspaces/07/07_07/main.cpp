/*
Lesson 7.7 - External linkage and variable forward declarations
LearnCpp: https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
Tasks:
- Forward declare g_dailyLimit as int and g_bonusLimit as const int using extern.
- Add the two linked values and print the calculated daily capacity.
Concept:
- An extern declaration without an initializer refers to a definition in another file.
Constraints:
- Do not define either variable here and do not include limits.cpp.
Exact expected output:
Daily capacity: 15
Completion checklist:
- Both declarations match limits.cpp and capacity is calculated from the variables.
- The C++20 target passes ./course check 7.7 without warnings.
*/
#include <iostream>

// TODO: Add matching extern declarations for both variables from limits.cpp.
extern int g_dailyLimit;
extern const int g_bonusLimit;

int main() {
    const int capacity{g_dailyLimit + g_bonusLimit}; // TODO: Add the two external variables.
    std::cout << "Daily capacity: " << capacity << '\n';
    return 0;
}
