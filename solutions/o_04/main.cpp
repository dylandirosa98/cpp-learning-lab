#include <iostream>

void printBit(int value, int placeValue)
{
    std::cout << (value / placeValue) % 2;
}

void print8BitBinary(int value)
{
    printBit(value, 128);
    printBit(value, 64);
    printBit(value, 32);
    printBit(value, 16);
    std::cout << ' ';
    printBit(value, 8);
    printBit(value, 4);
    printBit(value, 2);
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
