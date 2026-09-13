#include <bitset>
#include <iostream>

int main()
{
    const unsigned int status{ 0b1010'1100 };
    const unsigned int lowNibbleMask{ 0x0Fu };

    std::cout << "Status binary: " << std::bitset<8>{ status } << '\n';
    std::cout << "Low nibble mask hex: " << std::hex << lowNibbleMask << '\n';
    std::cout << "Status decimal: " << std::dec << status << '\n';
    return 0;
}
