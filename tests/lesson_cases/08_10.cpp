#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    for (int first{-8}; first <= 8; ++first)
        for (int last{-8}; last <= 8; ++last)
            for (int divisor{-1}; divisor <= 5; ++divisor)
            {
                int expected{0};
                if (divisor > 0)
                    for (int value{first}; value <= last; ++value)
                        if (value % divisor == 0) ++expected;
                checkEqual(countMultiples(first, last, divisor), expected, "countMultiples: inclusive range");
            }
    return 0;
}
