#include <iostream>

int main()
{
    constexpr bool inspectionPassed{ true };
    int approvedUnits{ 0 };

    if (inspectionPassed)
    {
        approvedUnits = 12;
        std::cout << "Inspection passed\n";
    }

    std::cout << "Units released: " << approvedUnits << '\n';
    return 0;
}
