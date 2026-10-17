/*
Lesson O.3 - Bit manipulation with bitwise operators and bit masks
LearnCpp: https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
Practice:
- Give one-bit masks meaningful names.
- Query, set, clear, and toggle packed flags with reusable functions.
Tasks:
1. Implement hasFlag with bitwise AND.
2. Implement setFlag with OR, clearFlag with AND and NOT, and toggleFlag with XOR.
3. Apply the requested operations to the article flags.
4. Print the packed pattern and three queried states.
Function responsibilities:
- The four flag functions each perform one reusable mask operation.
- main owns the scenario and output.
Constraints:
- Keep flag values and masks as std::uint8_t and cast results explicitly.
- Do not use std::bitset to manipulate flags or hard-code expected results.
Exact expected output:
Flags: 00001011
Viewed: true
Favorited: false
Shared: true
Completion checklist:
- Each function uses the bitwise operator appropriate to its purpose.
- The inverted clear mask is cast back to std::uint8_t.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check O.3
*/
#include <bitset>
#include <cstdint>
#include <iostream>

bool hasFlag(std::uint8_t flags, std::uint8_t mask)
{
    // TODO: Query only the selected bit.
    return flags == mask;
}

std::uint8_t setFlag(std::uint8_t flags, [[maybe_unused]] std::uint8_t mask)
{
    // TODO: Return flags with the selected bit enabled.
    return flags;
}

std::uint8_t clearFlag(std::uint8_t flags, [[maybe_unused]] std::uint8_t mask)
{
    // TODO: Invert the mask, narrow it safely, and clear the selected bit.
    return flags;
}

std::uint8_t toggleFlag(std::uint8_t flags, [[maybe_unused]] std::uint8_t mask)
{
    // TODO: Return flags with the selected bit inverted.
    return flags;
}

int main()
{
    constexpr std::uint8_t optionViewed{ 0b0000'0001 };
    [[maybe_unused]] constexpr std::uint8_t optionEdited{ 0b0000'0010 };
    constexpr std::uint8_t optionFavorited{ 0b0000'0100 };
    constexpr std::uint8_t optionShared{ 0b0000'1000 };

    std::uint8_t flags{ optionFavorited };
    // TODO: Set viewed and edited, clear favorited, and toggle shared.

    std::cout << std::boolalpha;
    std::cout << "Flags: " << std::bitset<8>{ flags } << '\n';
    std::cout << "Viewed: " << hasFlag(flags, optionViewed) << '\n';
    std::cout << "Favorited: " << hasFlag(flags, optionFavorited) << '\n';
    std::cout << "Shared: " << hasFlag(flags, optionShared) << '\n';
    return 0;
}
