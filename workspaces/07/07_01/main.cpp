/*
Lesson 7.1 - Compound statements (blocks)
LearnCpp: https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/
Practice:
- Use a compound statement where an if statement accepts one statement.
- Keep related conditional actions together without unnecessary nesting.
Tasks:
1. Complete the block controlled by if (inspectionPassed).
2. Inside it, assign 12 to approvedUnits and print the inspection message.
3. Print the released unit count after the conditional block.
Function responsibility:
- main applies one fixed inspection result and reports its effects.
Constraints:
- Both conditional actions must be inside the same block.
- Keep the exercise deterministic and do not read stdin or hard-code the final report value.
Exact expected output:
Inspection passed
Units released: 12
Completion checklist:
- The if statement controls a block containing two statements.
- The final unit report is outside that block and uses approvedUnits.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 7.1
*/
#include <iostream>

int main() {
    constexpr bool inspectionPassed{true};
    int approvedUnits{0};

    if (inspectionPassed) {
        // TODO: Put both required conditional actions here.
        // TODO put the things over here.
        approvedUnits = 12;
        std::cout << "Inspection passed\n";
    }

    std::cout << "Units released: " << approvedUnits << '\n';
    return 0;
}
