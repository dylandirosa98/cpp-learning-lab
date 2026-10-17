/*
Lesson 8.7 - Goto statements
LearnCpp: https://www.learncpp.com/cpp-tutorial/goto-statements/

Problem:
Implement a retry simulation with a backward goto. The first failuresBeforeSuccess attempts fail; the next succeeds. Return the successful attempt number (numbered from 1), or -1 if the attempt budget is exhausted. Negative failures or maxAttempts <= 0 are invalid and return -1. No printing or real network calls. This is a small goto demonstration, not a recommendation to use goto in ordinary retry code.

Expected results (examples):
- firstSuccessfulAttempt(0, 3) -> 1
- firstSuccessfulAttempt(2, 3) -> 3
- firstSuccessfulAttempt(3, 3) -> -1
- firstSuccessfulAttempt(-1, 3) -> -1

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.7
*/
#include <iostream>


int firstSuccessfulAttempt(int failuresBeforeSuccess, int maxAttempts)
{
    if (failuresBeforeSuccess < 0 || maxAttempts <= 0) return -1;
    int attempt{1};
retry:
    if (attempt > failuresBeforeSuccess) return attempt;
    if (attempt == maxAttempts) return -1;
    ++attempt;
    goto retry;
}

int main()
{
    return 0;
}
