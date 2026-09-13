/*
Lesson 6.1 - Operator precedence and associativity
LearnCpp: https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/
Practice:
- Predict default grouping before running the program.
- Use parentheses when addition must happen before multiplication.
Tasks:
1. Calculate defaultScore with basePoints + bonusPoints * multiplier.
2. Calculate groupedScore with (basePoints + bonusPoints) * multiplier.
3. Calculate pointsPerRound with totalPoints / teams / rounds.
4. Print all three calculated variables in the supplied order.
Function responsibility:
- main owns the fixed scoreboard inputs, performs each expression, and reports it.
Constraints:
- Do not replace expressions with their numeric answers or add stdin.
- Keep the two division operators unparenthesized to observe left associativity.
Exact expected output:
Default precedence: 22
Parenthesized: 42
Left-associated division: 5
Completion checklist:
- Multiplication binds first in defaultScore and parentheses alter groupedScore.
- Equal-precedence divisions associate from left to right.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 6.1
*/
#include <iostream>

int main()
{
    constexpr int basePoints{ 10 };
    constexpr int bonusPoints{ 4 };
    constexpr int multiplier{ 3 };
    constexpr int totalPoints{ 100 };
    constexpr int teams{ 4 };
    constexpr int rounds{ 5 };

    const int defaultScore{ basePoints + bonusPoints + multiplier }; // TODO: Let multiplication bind before addition.
    const int groupedScore{ basePoints + bonusPoints * multiplier }; // TODO: Group the addition explicitly.
    const int pointsPerRound{ totalPoints / teams * rounds }; // TODO: Use both left-associated divisions.

    std::cout << "Default precedence: " << defaultScore << '\n';
    std::cout << "Parenthesized: " << groupedScore << '\n';
    std::cout << "Left-associated division: " << pointsPerRound << '\n';
    return 0;
}
