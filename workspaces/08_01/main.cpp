/*
Lesson 8.1 - Control flow introduction
LearnCpp: https://www.learncpp.com/cpp-tutorial/control-flow-introduction/
Practice:
- Follow one execution path through a small deterministic program.
- Branch on a fixed comparison and print a different result per branch.
Tasks:
1. Complete the if branch so a score at or above passMark prints pass.
2. Complete the else branch so a lower score prints fail.
3. Keep both calls in main so both branches execute.
Function responsibility:
- printScoreResult compares score with passMark and prints one result line.
Constraints:
- Keep the exercise deterministic and do not read stdin.
- Do not hard-code the two result lines.
Exact expected output:
Score 72: pass
Score 45: fail
Completion checklist:
- The function uses one if statement and one else statement.
- Both supplied calls remain in main.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 8.1
*/
#include <iostream>

void printScoreResult(int score, int passMark) {
    std::cout << "Score " << score << ": ";
    if (score >= passMark) {
        // TODO: Print the pass result inside this block.
        std::cout << "pass\n";
    } else {
        // TODO: Print the fail result inside this block.
        std::cout << "fail\n";
    }
}

int main() {
    printScoreResult(72, 60);
    printScoreResult(45, 60);
    return 0;
}
