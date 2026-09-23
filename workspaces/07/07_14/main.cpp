/*
Lesson 7.14 - Unnamed and inline namespaces
LearnCpp: https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
Tasks:
- Call the legacy version through Pricing::V1.
- Call the inline current version through the parent Pricing namespace.
- Call that same current version explicitly through Pricing::V2.
Function responsibilities:
- main owns the fixed subtotal and demonstrates all three API spellings.
- pricing.cpp remains responsible for every pricing rule and implementation detail.
Constraints:
- Do not duplicate fee arithmetic, use namespace directives, or read stdin.
- Keep the subtotal as a named constexpr int.
Exact expected output:
Legacy total: 20
Default total: 23
Named current total: 23
Completion checklist:
- Each line calls the corresponding version rather than hard-coding a total.
- The default call omits the version because V2 is inline.
- The C++20 target builds warning-free and output matches exactly.
Run from project root: ./course check 7.14
*/
#include "pricing.h"

#include <iostream>

int main()
{
    constexpr int subtotal{ 20 };
    std::cout << "Legacy total: " << Pricing::V1::total(subtotal) << '\n';
    // TODO: Add calls through Pricing::total and Pricing::V2::total.
    return 0;
}
