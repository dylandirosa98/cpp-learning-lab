#ifndef CPP_LEARNING_LAB_CHAPTER6_INVENTORY_H
#define CPP_LEARNING_LAB_CHAPTER6_INVENTORY_H

#include <string_view>

int applesRemaining(int starting, int sold, int spoiled);
bool needsRestock(int remaining, int target);
int applesToRestock(int remaining, int target);
int cratesNeeded(int applesNeeded, int crateCapacity);
std::string_view appleLabel(int quantity);

#endif
