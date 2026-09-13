/*
Lesson 6.6 - The conditional operator
LearnCpp: https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
Practice:
- Use one condition to select numeric and text expression results.
- Store each selected value with the type it naturally produces.
Tasks:
1. Compare subtotal with freeShippingThreshold.
2. Select shippingCharge as 0 when qualified and 7 otherwise.
3. Select shippingTier as the string view "free" or "standard".
4. Add subtotal and shippingCharge and print the report.
Function responsibility:
- main applies a fixed shipping policy and reports its selected values.
Constraints:
- Use conditional operators for both selections; do not hard-code the total.
- Keep alternatives simple and do not add stdin.
Exact expected output:
Shipping tier: standard
Shipping charge: 7
Order total: 49
Completion checklist:
- The relational condition drives both conditional expressions.
- The total is arithmetic over subtotal and selected shipping charge.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 6.6
*/
#include <iostream>
#include <string_view>

int main()
{
    constexpr int subtotal{ 42 };
    constexpr int freeShippingThreshold{ 50 };

    const bool qualifiesForFreeShipping{ subtotal == freeShippingThreshold }; // TODO: Use the threshold policy.
    const int shippingCharge{ qualifiesForFreeShipping ? 7 : 0 }; // TODO: Select 0 or 7 in the correct order.
    const std::string_view shippingTier{ qualifiesForFreeShipping ? "standard" : "free" }; // TODO: Correct both alternatives.
    const int orderTotal{ subtotal - shippingCharge }; // TODO: Add subtotal and shippingCharge.

    std::cout << "Shipping tier: " << shippingTier << '\n';
    std::cout << "Shipping charge: " << shippingCharge << '\n';
    std::cout << "Order total: " << orderTotal << '\n';
    return 0;
}
