/*
Lesson 8.12 - Halts (exiting your program early)
LearnCpp: https://www.learncpp.com/cpp-tutorial/halts-exiting-your-program-early/

Problem:
Implement exitForStatus using std::exit. Status 0 means success: terminate the PROCESS with exit code 0. Status 1 means retry later: exit code 2. Any other status means failure: exit code 1. This function must never return. Do not print anything. The checker starts a fresh child process for each status, so this cannot terminate the course checker itself.

Expected results (examples):
- exitForStatus(0) -> process exits 0
- exitForStatus(1) -> process exits 2
- exitForStatus(2) -> process exits 1
- exitForStatus(-1) -> process exits 1

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.12
*/
#include <iostream>
#include <cstdlib>


void exitForStatus(int statusCode)
{
// TODO: Implement the behavior described above.
    (void)statusCode;
}

int main()
{
    exitForStatus(0);
    return 0;
}
