/*
Lesson 7.13 - Using declarations and using directives
LearnCpp: https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
Practice:
- Select one qualified name for local unqualified use.
- Keep a colliding name from another namespace explicitly qualified.
Tasks:
1. Define Inventory::status as the string view "ready".
2. Define Shipping::status as the string view "dispatched".
3. Inside main, introduce only Inventory::status with a using-declaration.
4. Print Inventory's status unqualified and Shipping's status qualified.
Function responsibilities:
- The namespaces own two distinct constants with the same unqualified name.
- main limits shorthand lookup to one selected name in its own block.
Constraints:
- Do not use a using-directive or add a using-statement to a header.
- Keep all includes before the using-declaration and do not read stdin.
Exact expected output:
Inventory: ready
Shipping: dispatched
Completion checklist:
- The local using-declaration names only Inventory::status.
- Shipping::status remains explicitly qualified at its use.
- The C++20 target builds warning-free and output matches exactly.
Run from project root: ./course check 7.13
*/
#include <iostream>
#include <string_view>

namespace Inventory
{
    constexpr std::string_view status{ "waiting" };
}

namespace Shipping
{
    constexpr std::string_view status{ "waiting" };
}

int main()
{
    // TODO: Introduce only Inventory::status, then use it without qualification.
    std::cout << "Inventory: " << Inventory::status << '\n';
    std::cout << "Shipping: " << Shipping::status << '\n';
    return 0;
}
