/*
Lesson 5.3 - Numeral systems (decimal, binary, hexadecimal, and octal)
LearnCpp:
https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/
Practice:
- Express bit-oriented values with binary and hexadecimal literals.
- Use std::bitset for binary output and manage sticky stream bases.
Task:
1. Replace status's decimal initializer with 0b1010'1100.
2. Replace lowNibbleMask's decimal initializer with 0x0Fu.
3. Keep std::bitset<8> so the binary display includes all eight positions.
4. Reset std::cout with std::dec immediately before the final status value.
Function responsibility:
- main defines two bit-oriented values and presents them in three numeral systems.
Constraints:
- Use actual binary and hexadecimal literals rather than strings containing digits.
- Keep std::hex for the mask and demonstrate its explicit reset with std::dec.
Exact expected output:
Status binary: 10101100
Low nibble mask hex: f
Status decimal: 172
Completion checklist:
- The literals make bit groupings and the nibble mask visible in source.
- std::bitset prints eight binary digits and decimal output follows std::dec.
- The program builds warning-free as C++20.
Run from project root: ./course check 5.3
*/
#include <bitset>
#include <iostream>

int main() {
    const unsigned int status{0b1010'1100};
    const unsigned int lowNibbleMask{0x0Fu};

    std::cout << "Status binary: " << std::bitset<8>{status} << '\n';
    std::cout << "Low nibble mask hex: " << std::hex << lowNibbleMask << '\n';

    std::cout << "Status decimal: " << std::dec << status << '\n';
    return 0;
}
