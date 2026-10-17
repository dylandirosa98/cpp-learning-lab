#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
#include <string>
int main()
{
    for (int value : {0, 1, 9, 10, 99, 100, 999, 1000, 1000000, 2147483647})
        checkEqual(digitCount(value), static_cast<int>(std::to_string(value).size()), "digitCount: decimal boundaries");
    for (int value : {-1, -100, -2147483647}) checkEqual(digitCount(value), -1, "digitCount: negative input");
    return 0;
}
