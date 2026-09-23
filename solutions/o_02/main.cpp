#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> left{ 0b0011'1100 };
    std::bitset<8> right{ 0b0000'1010 };

    std::cout << "AND: " << (left & right) << '\n';
    std::cout << "OR: " << (left | right) << '\n';
    std::cout << "XOR: " << (left ^ right) << '\n';
    std::cout << "NOT: " << (~left) << '\n';
    std::cout << "Left: " << (left << 1) << '\n';
    std::cout << "Right: " << (left >> 2) << '\n';
    return 0;
}
