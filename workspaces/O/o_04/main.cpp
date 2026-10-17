/*
Lesson O.4 - Converting integers between binary and decimal representation
LearnCpp: https://www.learncpp.com/cpp-tutorial/converting-integers-between-binary-and-decimal-representation/
Practice:
- Derive binary digits from decimal values using place values.
- Format reusable eight-bit output without bit utilities.
Tasks:
1. Implement printBit with integer division and remainder.
2. Call it for all eight powers of two in print8BitBinary.
3. Separate the two four-bit groups with one space.
4. Convert the supplied decimal values from main.
Function responsibilities:
- printBit writes one calculated binary digit.
- print8BitBinary coordinates all eight positions and grouping.
- main labels the two deterministic conversions.
Constraints:
- Do not use std::bitset, bitwise operators, stdin, or binary strings.
- Calculate every displayed digit from value and placeValue.
Exact expected output:
93 decimal: 0101 1101
148 decimal: 1001 0100
Completion checklist:
- Each digit is calculated as (value / placeValue) % 2.
- The positions run from 128 down to 1 with grouping after 16.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check O.4
*/
#include <iostream>

void printBit(int value, int placeValue)
{
    // TODO: Print the bit at placeValue using division and remainder.
    std::cout << value - value + placeValue - placeValue;
}

void print8BitBinary(int value)
{
    // TODO: Print positions 128 through 1, with a space between the nibbles.
    printBit(value, 1);
}

int main()
{
    std::cout << "93 decimal: ";
    print8BitBinary(93);
    std::cout << '\n';

    std::cout << "148 decimal: ";
    print8BitBinary(148);
    std::cout << '\n';
    return 0;
}
