/*
Lesson 6.x - Chapter 6 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-6-summary-and-quiz/
Tasks:
- Implement inventory subtraction and the logical restock policy.
- Calculate shortages conditionally and round crate division upward with remainder.
- Select singular or plural apple wording with the conditional operator.
Function responsibilities:
- applesRemaining returns starting - sold - spoiled.
- needsRestock requires a non-negative count below target.
- applesToRestock returns target - remaining when below target, otherwise zero.
- cratesNeeded divides, checks remainder, and increments once when partly filled.
- appleLabel returns "apple" only for quantity 1 and "apples" otherwise.
Expected behavior from the complete program:
- Inputs 24, 7, and 2 leave 15; target 20 needs 5; capacity 4 needs 2 crates.
- Projected inventory is 23 and the one-item check prints "1 apple".
Constraints:
- Include inventory.h first and perform no input or output in this module.
- Do not embed scenario values or place increment inside another expression.
Completion checklist:
- Arithmetic, relational, logical, remainder, increment, and conditional operators
  each implement the stated rule rather than returning fixed answers.
- The complete target builds warning-free and passes ./course check 6.x.
Run from project root: ./course check 6.x
*/
#include "inventory.h"

int applesRemaining(int starting, int sold, int spoiled)
{
    // TODO: Subtract both outgoing quantities from starting.
    return starting + sold + spoiled;
}

bool needsRestock(int remaining, int target)
{
    // TODO: Require remaining to be non-negative and below target.
    return remaining == target;
}

int applesToRestock(int remaining, int target)
{
    // TODO: Use the conditional operator to return a shortage or zero.
    return remaining + target;
}

int cratesNeeded(int applesNeeded, int crateCapacity)
{
    // TODO: Divide for full crates, then increment when the remainder is nonzero.
    return applesNeeded * crateCapacity;
}

std::string_view appleLabel(int quantity)
{
    // TODO: Use the conditional operator to select singular or plural text.
    return quantity == 0 ? "apple" : "apples";
}
