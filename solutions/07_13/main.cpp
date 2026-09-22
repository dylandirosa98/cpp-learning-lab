#include <iostream>
#include <string_view>

namespace Inventory
{
    constexpr std::string_view status{ "ready" };
}

namespace Shipping
{
    constexpr std::string_view status{ "dispatched" };
}

int main()
{
    using Inventory::status;
    std::cout << "Inventory: " << status << '\n';
    std::cout << "Shipping: " << Shipping::status << '\n';
    return 0;
}
