/*
Lesson 7.3 - Local variables
LearnCpp: https://www.learncpp.com/cpp-tutorial/local-variables/
Practice:
- Match each local variable's block scope to where its value is needed.
- Use an outer local from a nested block and after that block ends.
Tasks:
1. Declare itemsRemaining as 9 in main's outer block.
2. Inside the supplied nested block, declare const packedItems as 4.
3. Subtract packedItems from itemsRemaining and print the packed amount there.
4. Print itemsRemaining after leaving the nested block.
Function responsibility:
- main demonstrates the scopes and automatic lifetimes of fixed local variables.
Constraints:
- packedItems must exist only in the nested block; itemsRemaining must exist outside it.
- Keep the exercise deterministic and do not read stdin or hard-code calculated output.
Exact expected output:
Starting items: 9
Packed in inner scope: 4
Items after block: 5
Completion checklist:
- Each local is declared in the smallest supplied scope that needs it.
- The inner block updates the still-live outer local.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 7.3
*/
#include <iostream>

int main() {
    // TODO: Declare the outer local itemsRemaining with the required starting value.
    int itemsRemaining{9};
    std::cout << "Starting items: " << itemsRemaining << '\n';

    {
        // TODO: Declare packedItems here, then update and report the outer local.
        const int packedItems{4};
        itemsRemaining -= packedItems;
        std::cout << "Packed in inner scope: " << packedItems << '\n';
    }

    std::cout << "Items after block: " << itemsRemaining << '\n';
    return 0;
}
