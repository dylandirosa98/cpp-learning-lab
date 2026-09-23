#include <bitset>
#include <cstddef>
#include <iostream>

int main()
{
    constexpr std::size_t readPosition{ 0 };
    constexpr std::size_t writePosition{ 1 };
    [[maybe_unused]] constexpr std::size_t sharePosition{ 2 };
    constexpr std::size_t adminPosition{ 3 };

    std::bitset<8> permissions{ 0b0000'0101 };
    permissions.set(writePosition);
    permissions.reset(readPosition);
    permissions.flip(adminPosition);

    std::cout << std::boolalpha;
    std::cout << "Permissions: " << permissions << '\n';
    std::cout << "Read: " << permissions.test(readPosition) << '\n';
    std::cout << "Write: " << permissions.test(writePosition) << '\n';
    std::cout << "Enabled count: " << permissions.count() << '\n';
    return 0;
}
