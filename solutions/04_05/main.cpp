#include <iostream>

int main()
{
    int available{ 2 };
    int requested{ 3 };
    int balance{ available - requested };
    bool canFulfill{ available >= requested };

    std::cout << "Inventory balance: " << balance << '\n';
    std::cout << "Can fulfill: " << std::boolalpha << canFulfill << '\n';
    return 0;
}
