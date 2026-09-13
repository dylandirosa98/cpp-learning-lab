#include <cmath>
#include <iostream>

int main()
{
    constexpr int startDay{ 5 };
    constexpr int dayOffset{ 4 };
    constexpr int daysPerWeek{ 7 };
    constexpr int shipmentCount{ 18 };
    constexpr int base{ 2 };
    constexpr int exponent{ 5 };

    const int wrappedDay{ (startDay + dayOffset) % daysPerWeek };
    const bool shipmentIsEven{ shipmentCount % 2 == 0 };
    const double power{ std::pow(base, exponent) };

    std::cout << std::boolalpha;
    std::cout << "Wrapped weekday index: " << wrappedDay << '\n';
    std::cout << "Shipment is even: " << shipmentIsEven << '\n';
    std::cout << "2 to the power 5: " << power << '\n';
    return 0;
}
