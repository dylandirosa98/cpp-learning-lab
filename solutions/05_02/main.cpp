#include <iomanip>
#include <iostream>

int main()
{
    const float litersPerCan{ 1.5f };
    const unsigned int cansPerCase{ 8u };
    const long long annualCapacity{ 1'000'000LL };
    const float litersPerCase{ litersPerCan * cansPerCase };

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Case volume: " << litersPerCase << " liters\n";
    std::cout << "Annual capacity: " << annualCapacity << " cans\n";
    return 0;
}
