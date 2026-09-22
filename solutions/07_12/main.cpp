#include "counter.h"

#include <iostream>

int main()
{
    std::cout << "Daily limit: " << g_dailyLimit << '\n';

    {
        const int first{ visitsToday() };
        const int second{ visitsToday() };
        const int third{ visitsToday() };
        std::cout << "Visit: " << first << '\n';
        std::cout << "Visit: " << second << '\n';
        std::cout << "Visit: " << third << '\n';
    }

    return 0;
}
