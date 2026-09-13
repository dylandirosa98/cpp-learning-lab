/*
Lesson 6.5 - The comma operator
LearnCpp: https://www.learncpp.com/cpp-tutorial/the-comma-operator/
Practice:
- Evaluate a left-side mutation before a right-side calculation.
- Parenthesize the low-precedence comma operator deliberately.
Tasks:
1. Initialize auditResult with one parenthesized comma expression.
2. Use auditCode += 2 as its left operand.
3. Use auditCode * 3 as its right operand and yielded result.
4. Print the changed auditCode and calculated auditResult.
Function responsibility:
- main contains one focused comma-operator demonstration and its report.
Constraints:
- Do not split the required comma expression or hard-code result 18.
- Keep other sequencing straightforward and do not read input.
Exact expected output:
Audit code after left operand: 6
Comma expression result: 18
Completion checklist:
- The full comma expression is parenthesized inside the initializer.
- Its left side changes auditCode before its right side calculates the result.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 6.5
*/
#include <iostream>

int main()
{
    int auditCode{ 4 };
    int auditResult{}; // TODO: Use (auditCode += 2, auditCode * 3).

    std::cout << "Audit code after left operand: " << auditCode << '\n';
    std::cout << "Comma expression result: " << auditResult << '\n';
    return 0;
}
