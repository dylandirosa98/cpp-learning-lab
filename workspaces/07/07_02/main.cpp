/*
Lesson 7.2 - User-defined namespaces and the scope resolution operator
LearnCpp:
https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
Practice:
- Prevent identical function names from colliding by placing them in namespaces.
- Select each function explicitly with the scope resolution operator.
Tasks:
1. In Shipping, make fee return baseCharge + 2.
2. In Billing, make fee return baseCharge + 5.
3. Qualify both calls in main with the appropriate namespace names.
Function responsibilities:
- Shipping::fee calculates the shipping charge.
- Billing::fee calculates the billing charge, and main reports both fixed results.
Constraints:
- Preserve both fee(int) names and do not use a using directive.
- Keep the exercise deterministic and do not read stdin or hard-code calculated results.
Exact expected output:
Shipping fee: 12
Billing fee: 15
Completion checklist:
- Both fee functions have the same signature but occupy different namespaces.
- Both call sites use :: to remove ambiguity.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 7.2
*/
#include <iostream>

namespace Shipping {
int fee(int baseCharge) {
    // TODO: Add Shipping's fee adjustment.
    return baseCharge + 2;
}
} // namespace Shipping

namespace Billing {
int fee(int baseCharge) {
    // TODO: Add Billing's fee adjustment.
    return baseCharge + 5;
}
} // namespace Billing

int main() {
    constexpr int baseCharge{10};

    // TODO: Qualify each fee call with the namespace that owns it.
    std::cout << "Shipping fee: " << Shipping::fee(baseCharge) << '\n';
    std::cout << "Billing fee: " << Billing::fee(baseCharge) << '\n';
    return 0;
}
