#include <iostream>

void printDispatchStatus(int packed, int total)
{
    std::cout << "Packed orders: " << packed << " of " << total << '\n';
}

void runReport()
{
    printDispatchStatus(18, 24);
}

int main()
{
    runReport();
    return 0;
}
