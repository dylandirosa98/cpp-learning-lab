#include <iostream>

int remainingUnits(int available, int issued, int returned)
{
    int afterIssue{ available - issued };
    int finalCount{ afterIssue + returned };
    return finalCount;
}

int main()
{
    int reserve{ remainingUnits(52, 17, 4) };
    std::cout << "Reserve remaining: " << reserve << " units\n";
    return 0;
}
