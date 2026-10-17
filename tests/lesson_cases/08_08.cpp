#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    for (int limit{-10}; limit <= 1000; ++limit)
    {
        const int expected{limit > 0 ? limit * (limit + 1) / 2 : 0};
        checkEqual(sumUpTo(limit), expected, "sumUpTo: inclusive sum");
    }
    return 0;
}
