#include "inventory.h"

int applesRemaining(int starting, int sold, int spoiled)
{
    return starting - sold - spoiled;
}

bool needsRestock(int remaining, int target)
{
    return remaining >= 0 && remaining < target;
}

int applesToRestock(int remaining, int target)
{
    return remaining < target ? target - remaining : 0;
}

int cratesNeeded(int applesNeeded, int crateCapacity)
{
    int crates{ applesNeeded / crateCapacity };
    if (applesNeeded % crateCapacity != 0)
        ++crates;

    return crates;
}

std::string_view appleLabel(int quantity)
{
    return quantity == 1 ? "apple" : "apples";
}
