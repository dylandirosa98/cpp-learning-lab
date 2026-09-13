#include <iostream>
#include <string_view>

int main()
{
    constexpr int subtotal{ 42 };
    constexpr int freeShippingThreshold{ 50 };

    const bool qualifiesForFreeShipping{ subtotal >= freeShippingThreshold };
    const int shippingCharge{ qualifiesForFreeShipping ? 0 : 7 };
    const std::string_view shippingTier{ qualifiesForFreeShipping ? "free" : "standard" };
    const int orderTotal{ subtotal + shippingCharge };

    std::cout << "Shipping tier: " << shippingTier << '\n';
    std::cout << "Shipping charge: " << shippingCharge << '\n';
    std::cout << "Order total: " << orderTotal << '\n';
    return 0;
}
