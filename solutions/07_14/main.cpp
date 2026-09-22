#include "pricing.h"

#include <iostream>

int main()
{
    constexpr int subtotal{ 20 };
    std::cout << "Legacy total: " << Pricing::V1::total(subtotal) << '\n';
    std::cout << "Default total: " << Pricing::total(subtotal) << '\n';
    std::cout << "Named current total: " << Pricing::V2::total(subtotal) << '\n';
    return 0;
}
