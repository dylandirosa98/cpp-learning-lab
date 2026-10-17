/*
Lesson 8.2 - If statements and blocks
LearnCpp: https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
Practice:
- Control several statements with one if condition using a block.
- Chain conditions with else if and finish with else.
Tasks:
1. Keep the grade A block and add the distinction status as its second statement.
2. Complete the else if branch for scores of 80 or above.
3. Complete the final else branch for every lower score.
Function responsibility:
- printGrade classifies one supplied score and prints its report lines.
Constraints:
- Group the two distinction lines inside one block.
- Keep the exercise deterministic and do not read stdin.
Exact expected output:
Grade: A
Status: distinction
Grade: B
Grade: C or lower
Completion checklist:
- The grade A branch is a block containing two statements.
- The chain uses if, else if, and a final else.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 8.2
*/
#include <iostream>

void printGrade(int score)
{
    if (score >= 90)
    {
        std::cout << "Grade: A\n";
        // TODO: Print the distinction status as the second statement in this block.
    }
    else if (score >= 80)
    {
        // TODO: Print the grade B line here.
    }
    else
    {
        // TODO: Print the grade C-or-lower line here.
    }
}

int main()
{
    printGrade(95);
    printGrade(82);
    printGrade(60);
    return 0;
}
