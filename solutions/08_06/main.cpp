/*
Lesson 8.6 - Switch fallthrough and scoping
LearnCpp: https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/

Problem:
Implement rankScore. Valid ranks 0 through 3 start with 100 points. Rank 1 adds 10; rank 2 earns the rank-1 bonus plus 25; rank 3 earns both lower bonuses plus 50. Return -1 for invalid ranks. Practice a switch with intentional fallthrough and [[fallthrough]] between bonus cases; keep any case-local declarations in a block.

Expected results (examples):
- rankScore(0) -> 100
- rankScore(1) -> 110
- rankScore(2) -> 135
- rankScore(3) -> 185
- rankScore(4) -> -1

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.6
*/
#include <iostream>


int rankScore(int rank)
{
    if (rank < 0 || rank > 3) return -1;
    int score{100};
    switch (rank)
    {
        case 3:
        {
            const int bonus{50};
            score += bonus;
        }
        [[fallthrough]];
        case 2: score += 25; [[fallthrough]];
        case 1: score += 10; break;
        case 0: break;
    }
    return score;
}

int main()
{
    return 0;
}
