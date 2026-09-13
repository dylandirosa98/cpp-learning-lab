#include <iostream>

int addHandoffMinutes(int travelMinutes)
{
    return travelMinutes + 5;
}

int estimateDispatchMinutes(int warehouseLeg, int customerLeg)
{
    int travelMinutes{ warehouseLeg + customerLeg };
    return addHandoffMinutes(travelMinutes);
}

int main()
{
    int totalMinutes{ estimateDispatchMinutes(18, 27) };
    std::cout << "Dispatch estimate: " << totalMinutes << " minutes\n";
    return 0;
}
