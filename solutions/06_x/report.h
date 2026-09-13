#ifndef CPP_LEARNING_LAB_CHAPTER6_REPORT_H
#define CPP_LEARNING_LAB_CHAPTER6_REPORT_H

#include <string_view>

void printHeading();
void printQuantity(std::string_view description, int quantity);
void printStatus(bool restockRequired);
void printCrates(int crates);

#endif
