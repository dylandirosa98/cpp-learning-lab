#include <bitset>
#include <cstdint>
#include <iostream>

bool hasFlag(std::uint8_t flags, std::uint8_t mask)
{
    return static_cast<bool>(flags & mask);
}

std::uint8_t setFlag(std::uint8_t flags, std::uint8_t mask)
{
    return static_cast<std::uint8_t>(flags | mask);
}

std::uint8_t clearFlag(std::uint8_t flags, std::uint8_t mask)
{
    return static_cast<std::uint8_t>(flags & static_cast<std::uint8_t>(~mask));
}

std::uint8_t toggleFlag(std::uint8_t flags, std::uint8_t mask)
{
    return static_cast<std::uint8_t>(flags ^ mask);
}

int main()
{
    constexpr std::uint8_t optionViewed{ 0b0000'0001 };
    constexpr std::uint8_t optionEdited{ 0b0000'0010 };
    constexpr std::uint8_t optionFavorited{ 0b0000'0100 };
    constexpr std::uint8_t optionShared{ 0b0000'1000 };

    std::uint8_t flags{ optionFavorited };
    flags = setFlag(flags, optionViewed);
    flags = setFlag(flags, optionEdited);
    flags = clearFlag(flags, optionFavorited);
    flags = toggleFlag(flags, optionShared);

    std::cout << std::boolalpha;
    std::cout << "Flags: " << std::bitset<8>{ flags } << '\n';
    std::cout << "Viewed: " << hasFlag(flags, optionViewed) << '\n';
    std::cout << "Favorited: " << hasFlag(flags, optionFavorited) << '\n';
    std::cout << "Shared: " << hasFlag(flags, optionShared) << '\n';
    return 0;
}
