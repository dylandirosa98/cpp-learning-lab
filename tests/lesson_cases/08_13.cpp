#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    checkEqual(rawDraw(42, 0), 1608637542u, "rawDraw(42, 0)");
    checkEqual(rawDraw(42, 1), 3421126067u, "rawDraw(42, 1)");
    checkEqual(rawDraw(5489, 0), 3499211612u, "rawDraw(5489, 0)");
    for (unsigned int seed : {0u, 1u, 42u, 5489u, 98765u})
    {
        std::mt19937 expected{seed};
        checkEqual(rawDraw(seed, -1), 0u, "rawDraw: negative index");
        for (int index{0}; index <= 100; ++index)
        {
            const auto draw{expected()};
            checkEqual(rawDraw(seed, index), draw, "rawDraw: seeded sequence");
            checkEqual(rawDraw(seed, index), draw, "rawDraw: repeatable call");
        }
    }
    return 0;
}
