/*
Lesson 6.x - Chapter 6 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-6-summary-and-quiz/
Tasks:
- Declare the inventory arithmetic, restock decision, crate, and label interfaces.
- Keep each operation independent of console presentation and fixed scenario values.
Function responsibilities:
- applesRemaining subtracts sold and spoiled quantities from the starting count.
- needsRestock combines validity and threshold comparisons into one boolean policy.
- applesToRestock calculates a non-negative shortage; cratesNeeded rounds it up.
- appleLabel returns a non-owning singular or plural label selected by quantity.
Expected behavior from the complete program:
- The scenario leaves 15 apples, needs 5 apples, orders 2 crates, and projects 23.
- A quantity of 1 uses "apple" while every other demonstrated count uses "apples".
Constraints:
- Keep this header declaration-only and protect it with the unique include guard.
- Do not include streams, define scenario constants, or import namespace std.
Completion checklist:
- Signatures match inventory.cpp and use std::string_view for the label.
- Every declaration is inside the include guard.
- The complete target builds warning-free and passes ./course check 6.x.
Run from project root: ./course check 6.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER6_INVENTORY_H
#define CPP_LEARNING_LAB_CHAPTER6_INVENTORY_H

#include <string_view>

int applesRemaining(int starting, int sold, int spoiled);
bool needsRestock(int remaining, int target);
int applesToRestock(int remaining, int target);
int cratesNeeded(int applesNeeded, int crateCapacity);
std::string_view appleLabel(int quantity);

#endif
