/*
Lesson O.1 - Bit flags and bit manipulation via std::bitset
LearnCpp: https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/
Practice:
- Treat individual std::bitset positions as named Boolean flags.
- Manipulate and query flags with std::bitset member functions.
Tasks:
1. Enable write with set().
2. Disable read with reset().
3. Invert admin with flip().
4. Print the final bits, queried states, and enabled count.
Function responsibilities:
- main owns the named positions, permission bits, mutations, and report.
Constraints:
- Use set, reset, flip, test, and count rather than replacing the bitset.
- Do not hard-code the expected results or read stdin.
Exact expected output:
Permissions: 00001110
Read: false
Write: true
Enabled count: 3
Completion checklist:
- Position names document what each bit means.
- Every requested member function is used for its intended operation.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check O.1
*/
#include <bitset>
#include <cstddef>
#include <iostream>

int main()
{
    constexpr std::size_t readPosition{ 0 };
    constexpr std::size_t writePosition{ 1 };
    [[maybe_unused]] constexpr std::size_t sharePosition{ 2 };
    [[maybe_unused]] constexpr std::size_t adminPosition{ 3 };

    std::bitset<8> permissions{ 0b0000'0101 };

    // TODO: Enable write, disable read, and flip admin.
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
