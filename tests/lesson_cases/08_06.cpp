#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    const int expected[]{100, 110, 135, 185};
    for (int rank{0}; rank < 4; ++rank) checkEqual(rankScore(rank), expected[rank], "rankScore: accumulated bonus");
    for (int rank : {-100, -1, 4, 10, 100}) checkEqual(rankScore(rank), -1, "rankScore: invalid rank");
    return 0;
}
