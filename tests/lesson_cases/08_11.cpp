#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    for (int limit{-2}; limit <= 40; ++limit)
        for (int stop{-2}; stop <= 45; ++stop)
        {
            int expected{0};
            const int end{stop >= 1 && stop <= limit ? stop - 1 : limit};
            for (int value{1}; value <= end; ++value)
                if (value % 3 != 0) expected += value;
            checkEqual(sumCheckpoints(limit, stop), expected, "sumCheckpoints: stop before skip");
        }
    return 0;
}
