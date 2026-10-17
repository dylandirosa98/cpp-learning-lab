/*
Lesson 8.4 - Constexpr if statements
LearnCpp: https://www.learncpp.com/cpp-tutorial/constexpr-if-statements/
Practice:
- Branch on compile-time constants with if constexpr.
- Provide both a taken and a discarded branch.
Tasks:
1. Complete the if constexpr (debugBuild) statement with its else branch.
2. Complete the if constexpr (verboseBuild) statement with its else branch.
3. Keep both statements in printBuildReport.
Function responsibility:
- printBuildReport prints the build report selected by the two compile-time flags.
Constraints:
- The conditions must be the constexpr variables, not function parameters.
- Keep the exercise deterministic and do not read stdin.
Exact expected output:
Build: debug
Verbose: no
Completion checklist:
- Both statements use if constexpr with an else branch.
- debugBuild is true and verboseBuild is false.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 8.4
*/
#include <iostream>

constexpr bool debugBuild{ true };
constexpr bool verboseBuild{ false };

void printBuildReport()
{
    if constexpr (debugBuild)
    {
        std::cout << "Build: debug\n";
    }
    else
    {
        std::cout << "Build: release\n";
    }

    if constexpr (verboseBuild)
    {
        std::cout << "Verbose: yes\n";
    }
    else
    {
        std::cout << "Verbose: no\n";
    }
}

int main()
{
    printBuildReport();
    return 0;
}
