#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
#include <random>
int drawFromOtherFile(int min, int max);
int main()
{
    Random::reset(5489);
    checkEqual(Random::get(1, 4), 4, "Random: first roll");
    checkEqual(drawFromOtherFile(1, 4), 1, "Random: another translation unit shares the engine");
    checkEqual(Random::get(0, 1), 1, "Random: sequence continues across files");
    for (unsigned int seed : {0u, 42u, 5489u, 1234u})
    {
        Random::reset(seed);
        std::mt19937 generator{seed};
        for (int index{0}; index < 100; ++index)
        {
            const int min{index % 2 ? -4 : 1};
            const int max{min + 3};
            std::uniform_int_distribution<int> draw{min, max};
            const int expected{draw(generator)};
            checkEqual(index % 2 ? Random::get(min, max) : drawFromOtherFile(min, max), expected, "Random: shared draws");
        }
        Random::reset(seed);
        std::mt19937 replay{seed};
        std::uniform_int_distribution<int> coin{0, 1};
        checkEqual(Random::get(0, 1), coin(replay), "Random: reset replays");
        checkEqual(Random::get(7, 7), 7, "Random: single-value range");
        std::uniform_int_distribution<int> single{7, 7};
        single(replay);
        std::uniform_int_distribution<int> eight{-4, 3};
        checkEqual(Random::get(-4, 3), eight(replay), "Random: eight-value range");
    }
    return 0;
}
