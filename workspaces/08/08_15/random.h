/*
Lesson 8.15 - Global random numbers (Random.h)
LearnCpp: https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h/

Problem:
Implement Random::reset(unsigned int seed) and Random::get(int min, int max) in 
random.h. reset reseeds one shared inline std::mt19937; get returns the next uniform
integer in the INCLUSIVE range, advancing that same engine. 
Use std::uniform_int_distribution<int>. Calls from different .cpp files must share 
the sequence, not get separate engines. Inputs always have min <= max and a power-of-two
range size (1, 2, 4, or 8); no invalid-range handling is required.

Expected results (examples):
- reset(5489); get(1,4); get(1,4); get(0,1) -> 4, 1, 1
- Resetting to the same seed replays the sequence.
- The next call from another .cpp file continues the same sequence.

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.15
*/
#ifndef CPP_LEARNING_LAB_RANDOM_H
#define CPP_LEARNING_LAB_RANDOM_H
#include <random>
namespace Random
{
// TODO: Define one shared inline engine here.
inline std::mt19937 mt {};
inline void reset(unsigned int seed)
{
    // TODO: Reseed the shared engine.
    mt = static_cast<std::mt19937>(seed);
}
inline int get(int min, int max)
{
    // TODO: Draw from the inclusive range using the shared engine.
    return std::uniform_int_distribution{min, max}(mt);   

}
}
#endif
