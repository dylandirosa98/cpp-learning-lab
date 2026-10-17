/*
Lesson 8.14 - Generating random numbers using Mersenne Twister
LearnCpp: https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/

Problem:
Implement rollTotal. Seed a fresh std::mt19937 with seed, then draw rolls values with 
std::uniform_int_distribution<int>{1, 4}. Return their sum, not printed roll lines. Return 
0 for rolls <= 0. Draw exactly once per roll and reset the engine on each function call. 
The four-sided range is intentionally a power of two; tested roll counts are at most 1000.

Expected results (examples):
- rollTotal(42, 4) -> 11
- rollTotal(42, 1) -> 2
- rollTotal(42, 0) -> 0
- rollTotal(42, -1) -> 0

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.14
*/
#include <iostream>
#include <random>


int rollTotal(unsigned int seed, int rolls)
{
// TODO: Implement the behavior described above.
    std::mt19937 mt{seed};
    if (rolls <= 0){
      return 0;
    }
    int sum {};
    std::uniform_int_distribution die4{1, 4};
    for (int i {}; i < rolls; i++){
      sum += die4(mt);
    }
    return sum;
}

int main()
{
    return 0;
}
