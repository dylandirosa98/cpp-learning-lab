/*
Lesson 8.10 - For statements
LearnCpp: https://www.learncpp.com/cpp-tutorial/for-statements/

Problem:
Implement countMultiples with a for loop. Count integers in the inclusive range [first, last] divisible by divisor. Zero counts as divisible by any positive divisor; negative multiples count too. Return 0 for first > last or divisor <= 0. Test ranges stay between -1000 and 1000, so incrementing cannot overflow.

Expected results (examples):
- countMultiples(1, 10, 3) -> 3
- countMultiples(-3, 3, 3) -> 3
- countMultiples(0, 0, 5) -> 1
- countMultiples(10, 1, 3) -> 0
- countMultiples(1, 10, 0) -> 0

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.10
*/
#include <iostream>


int countMultiples(int first, int last, int divisor)
{
// TODO: Implement the behavior described above.
    (void)first;
    (void)last;
    (void)divisor;
    return 0;
}

int main()
{
    return 0;
}
