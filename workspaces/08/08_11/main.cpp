/*
Lesson 8.11 - Break and continue
LearnCpp: https://www.learncpp.com/cpp-tutorial/break-and-continue/

Problem:
Ilement sumCheckpoints. Visit values 1 through limit in order. Stop BEFORE processing a value equal
to stopAt, even if it is a multiple of 3. Skip multiples of 3. Sum all other visited values. Use
break for the stop and continue for the skip. If limit <= 0 return 0; if stopAt is outside [1,
limit], scan the entire range. Limits are at most 1000.

Expected results (examples):
- sumCheckpoints(10, 8) -> 19 (1+2+4+5+7)
- sumCheckpoints(10, 3) -> 3
- sumCheckpoints(5, 1) -> 0
- sumCheckpoints(5, 99) -> 12
- sumCheckpoints(5, 0) -> 12

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.11
*/
#include <iostream>

int sumCheckpoints(int limit, int stopAt) {
    // TODO: Implement the behavior described above.
    if (limit <= 0) {
        return 0;
    }
    int sum{};
    for (int i{1}; i <= limit; i++) {
        if (i == stopAt) {
            return sum;
        }
        if (i % 3 == 0) {
            continue;
        }
        sum += i;
    }
    return sum;
}

int main() {
    return 0;
}
