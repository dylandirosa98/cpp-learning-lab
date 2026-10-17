#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    for (int failures{-1}; failures <= 12; ++failures)
        for (int budget{-1}; budget <= 12; ++budget)
        {
            const int expected{failures >= 0 && budget > failures ? failures + 1 : -1};
            checkEqual(firstSuccessfulAttempt(failures, budget), expected, "firstSuccessfulAttempt: retry budget");
        }
    return 0;
}
