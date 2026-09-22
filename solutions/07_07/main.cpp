#include <iostream>

extern int g_dailyLimit;
extern const int g_bonusLimit;

int main()
{
    const int capacity{ g_dailyLimit + g_bonusLimit };
    std::cout << "Daily capacity: " << capacity << '\n';
    return 0;
}
