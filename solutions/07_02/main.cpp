#include <iostream>

namespace Shipping
{
    int fee(int baseCharge)
    {
        return baseCharge + 2;
    }
}

namespace Billing
{
    int fee(int baseCharge)
    {
        return baseCharge + 5;
    }
}

int main()
{
    constexpr int baseCharge{ 10 };

    std::cout << "Shipping fee: " << Shipping::fee(baseCharge) << '\n';
    std::cout << "Billing fee: " << Billing::fee(baseCharge) << '\n';
    return 0;
}
