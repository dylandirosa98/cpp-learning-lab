/*
Lesson 8.8 - Introduction to loops and while statements
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/

Problem:
Implement sumUpTo with a while loop. Return the sum of every integer from 1 through limit,
inclusive. Return 0 when limit <= 0. The tested limits are at most 1000, so the sum fits in int. You
write the initialization, condition, accumulation, and increment yourself.

Expected results (examples):
- sumUpTo(0) -> 0
- sumUpTo(1) -> 1
- sumUpTo(5) -> 15
- sumUpTo(10) -> 55
- sumUpTo(-3) -> 0

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.8
*/
#include <iostream>

int sumUpTo(int limit) {
    // TODO: Implement the behavior described above.
    int sum{0};
    while (limit > 0) {
        sum += limit;
        limit -= 1;
    }
    return sum;
}

int main() {
    return 0;
}
