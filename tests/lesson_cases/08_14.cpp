#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    checkEqual(rollTotal(42, 4), 11, "rollTotal(42, 4)");
    for (unsigned int seed : {0u, 1u, 42u, 5489u, 12345u})
        for (int rolls : {-5, 0, 1, 2, 4, 20, 100, 1000})
        {
            std::mt19937 generator{seed};
            std::uniform_int_distribution<int> die{1, 4};
            int expected{0};
            for (int index{0}; index < rolls; ++index) expected += die(generator);
            checkEqual(rollTotal(seed, rolls), expected, "rollTotal: seeded four-sided rolls");
            checkEqual(rollTotal(seed, rolls), expected, "rollTotal: resets on each call");
        }
    return 0;
}
