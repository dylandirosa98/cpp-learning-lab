/*
Lesson 4.2 - Void
LearnCpp: https://www.learncpp.com/cpp-tutorial/void/
What is practiced:
- Use void functions for actions that do not return a value.
- Use an empty parameter list for a function that accepts no arguments.
Required repair:
1. Trace main into runReport and then into printDispatchStatus.
2. Confirm that printDispatchStatus receives packed as 18 and total as 24.
3. Repair only the order in which those parameter values are presented.
4. Keep both void calls as standalone statements and run the checker.
Function responsibilities:
- printDispatchStatus presents one report from its two parameters.
- runReport supplies fixed data and coordinates presentation.
- main invokes the report and returns process success.
Constraints:
- Keep both void return types, signatures, and the supplied call values.
- Do not return a value from either void function.
- Spell the no-argument function as runReport(), not runReport(void).
- Use no input, add no duplicate output, and do not import std.
Exact expected output:
Packed orders: 18 of 24
Completion checklist:
- packed and total appear in their semantic positions.
- runReport is called as a statement rather than used as a value.
- The C++20 build is warning-free and exactly one line is printed.
Run from project root: ./course check 4.2
*/
#include <iostream>

void printDispatchStatus(int packed, int total)
{
    std::cout << "Packed orders: " << packed << " of " << total << '\n';
}

void runReport()
{
    printDispatchStatus(18, 24);
}

int main()
{
    runReport();
    return 0;
}
