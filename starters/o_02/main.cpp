/*
Lesson O.2 - Bitwise operators
LearnCpp: https://www.learncpp.com/cpp-tutorial/bitwise-operators/
Practice:
- Apply each bitwise operator to visible eight-bit patterns.
- Parenthesize shifts and other bitwise expressions used with std::cout.
Tasks:
1. Calculate left AND right, OR, and XOR.
2. Flip every bit in left with NOT.
3. Shift left left once and right twice.
4. Print all six resulting patterns.
Function responsibilities:
- main constructs both operands and reports each operation.
Constraints:
- Use the actual bitwise operators, not hard-coded expected bitsets.
- Do not use logical operators or read stdin.
Exact expected output:
AND: 00001000
OR: 00111110
XOR: 00110110
NOT: 11000011
Left: 01111000
Right: 00001111
Completion checklist:
- &, |, ^, ~, <<, and >> are all applied to the supplied bitsets.
- Expressions are parenthesized clearly at the stream boundary.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check O.2
*/
#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> left{ 0b0011'1100 };
    std::bitset<8> right{ 0b0000'1010 };

    // TODO: Replace the placeholder expressions with all six bitwise operations.
    std::cout << "AND: " << left << '\n';
    std::cout << "OR: " << left << '\n';
    std::cout << "XOR: " << left << '\n';
    std::cout << "NOT: " << left << '\n';
    std::cout << "Left: " << left << '\n';
    std::cout << "Right: " << right << '\n';
    return 0;
}
