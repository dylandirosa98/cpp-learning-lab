#include <iostream>

int main()
{
    int totalAdjustment{ -13 };
    int intervalCount{ 5 };
    int wholeSteps{ totalAdjustment / intervalCount };
    int remainder{ totalAdjustment % intervalCount };

    std::cout << "Whole steps: " << wholeSteps << '\n';
    std::cout << "Remainder: " << remainder << '\n';
    return 0;
}
