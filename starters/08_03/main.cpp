/*
Lesson 8.3 - Common if statement problems
LearnCpp: https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
Practice:
- Keep conditions boolean and explicit.
- Use == for equality tests instead of assignments.
Tasks:
1. Keep the equality branch with its == condition.
2. Complete the less-than branch with a < condition.
3. Complete the final else for the greater-than case.
Function responsibility:
- printComparison classifies the order of two supplied values and prints one line.
Constraints:
- Never assign inside a condition.
- Keep the exercise deterministic and do not read stdin.
Exact expected output:
3 equals 3
2 is less than 5
9 is greater than 4
Completion checklist:
- The chain uses == first, then <, then a final else.
- No condition contains an assignment.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 8.3
*/
#include <iostream>

void printComparison(int left, int right)
{
    if (left == right)
    {
        std::cout << left << " equals " << right << '\n';
    }
    else if (left < right)
    {
        // TODO: Print the less-than line here.
    }
    else
    {
        // TODO: Print the greater-than line here.
    }
}

int main()
{
    printComparison(3, 3);
    printComparison(2, 5);
    printComparison(9, 4);
    return 0;
}
