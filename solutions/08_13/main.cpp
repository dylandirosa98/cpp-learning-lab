/*
Lesson 8.13 - Introduction to random number generation
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/

Problem:
Implement rawDraw. Construct a local std::mt19937 from seed and return its draw at zero-based drawIndex. Index 0 is the first raw engine output. Return 0 for a negative index. Every function call starts a fresh engine, so identical arguments must return identical results. No distribution and no std::rand. Tested indices are at most 100.

Expected results (examples):
- rawDraw(42, 0) -> 1608637542
- rawDraw(42, 1) -> 3421126067
- rawDraw(42, 2) -> 4083286876
- rawDraw(5489, 0) -> 3499211612
- rawDraw(42, -1) -> 0

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.13
*/
#include <iostream>
#include <cstdint>
#include <random>


std::uint32_t rawDraw(unsigned int seed, int drawIndex)
{
    if (drawIndex < 0) return 0;
    std::mt19937 generator{seed};
    for (int index{0}; index < drawIndex; ++index) generator();
    return generator();
}

int main()
{
    return 0;
}
