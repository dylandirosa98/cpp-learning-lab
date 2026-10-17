/* Behavioral assertions shared by the Chapter 8 test drivers. */
#ifndef CPP_LEARNING_LAB_BEHAVIOR_CHECK_H
#define CPP_LEARNING_LAB_BEHAVIOR_CHECK_H
#include <cstdlib>
#include <iostream>

template <typename Actual, typename Expected>
void checkEqual(const Actual& actual, const Expected& expected, const char* example)
{
    if (actual != expected)
    {
        std::cerr << example << ": expected " << expected << ", got " << actual << '\n';
        std::exit(90);
    }
}
#endif
