/*
Lesson 6.x - Chapter 6 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-6-summary-and-quiz/
Tasks:
- Name the complete deterministic apple scenario with constexpr int values.
- Request every inventory result from inventory.cpp, then coordinate report calls.
- Calculate projected stock from remaining + crates * crateCapacity.
Function responsibilities:
- main owns fixed scenario inputs and the lifetime of all calculated results.
- main calls inventory functions in dependency order and presentation functions in
  the exact report order; it contains no stream output or duplicated policies.
Expected output:
- Apple inventory; Started 24, Sold 7, Spoiled 2, Remaining 15.
- Status restock required; Restock needed 5; Crates to order 2.
- Projected inventory 23; Pluralization check 1 apple.
Constraints:
- Do not include iostream, read stdin, include .cpp files, or hard-code results.
- Keep inventory arithmetic out of main except the requested projected expression.
Completion checklist:
- All five fixed inputs are constexpr int values with descriptive names.
- Remaining, decision, shortage, crate count, and projection use calculated values.
- The complete C++20 target is warning-clean and output matches exactly.
Run from project root: ./course check 6.x
*/
#include "inventory.h"
#include "report.h"

int main()
{
    constexpr int startingApples{ 24 };
    constexpr int soldApples{ 7 };
    constexpr int spoiledApples{ 2 };
    constexpr int targetApples{ 20 };
    constexpr int crateCapacity{ 4 };

    // TODO: Verify each inventory call, then correct the projected-stock expression.
    const int remaining{ applesRemaining(startingApples, soldApples, spoiledApples) };
    const bool restockRequired{ needsRestock(remaining, targetApples) };
    const int needed{ applesToRestock(remaining, targetApples) };
    const int crates{ cratesNeeded(needed, crateCapacity) };
    const int projected{ remaining + crates + crateCapacity };

    printHeading();
    printQuantity("Started", startingApples);
    printQuantity("Sold", soldApples);
    printQuantity("Spoiled", spoiledApples);
    printQuantity("Remaining", remaining);
    printStatus(restockRequired);
    printQuantity("Restock needed", needed);
    printCrates(crates);
    printQuantity("Projected inventory", projected);
    printQuantity("Pluralization check", 1);
    return 0;
}
