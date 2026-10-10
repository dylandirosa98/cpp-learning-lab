/*
Lesson 7.12 - Scope, duration, and linkage summary
LearnCpp: https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/
Tasks:
- Print the externally linked daily limit declared by counter.h.
- In a nested block, store three calls in const automatic local variables.
- Print the three retained visit counts in order.
Function responsibilities:
- main demonstrates external linkage plus nested block scope and automatic duration.
- visitsToday remains responsible for all persistent counting behavior.
Constraints:
- Do not define the daily limit or static counting state in main.
- Do not hard-code visit results or read stdin.
Exact expected output:
Daily limit: 3
Visit: 1
Visit: 2
Visit: 3
Completion checklist:
- The three results are const int locals inside the supplied nested block.
- Every value is obtained through the intended declaration or function call.
- The C++20 target builds warning-free and output matches exactly.
Run from project root: ./course check 7.12
*/
#include "counter.h"

#include <iostream>

int main() {
    std::cout << "Daily limit: " << g_dailyLimit << '\n';

    {
        // TODO: Store three visits in const automatic locals and print each one.
        const int first{visitsToday()};
        const int second{visitsToday()};
        const int third{visitsToday()};
        std::cout << "Visit: " << first << '\n';
        std::cout << "Visit: " << second << '\n';
        std::cout << "Visit: " << third << '\n';
    }

    return 0;
}
