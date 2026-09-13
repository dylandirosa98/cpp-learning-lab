#include "inventory.h"
#include "report.h"

int main()
{
    constexpr int startingApples{ 24 };
    constexpr int soldApples{ 7 };
    constexpr int spoiledApples{ 2 };
    constexpr int targetApples{ 20 };
    constexpr int crateCapacity{ 4 };

    const int remaining{ applesRemaining(startingApples, soldApples, spoiledApples) };
    const bool restockRequired{ needsRestock(remaining, targetApples) };
    const int needed{ applesToRestock(remaining, targetApples) };
    const int crates{ cratesNeeded(needed, crateCapacity) };
    const int projected{ remaining + crates * crateCapacity };

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
