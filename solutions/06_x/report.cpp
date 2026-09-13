#include "report.h"

#include "inventory.h"

#include <iostream>

void printHeading()
{
    std::cout << "Apple inventory\n";
}

void printQuantity(std::string_view description, int quantity)
{
    std::cout << description << ": " << quantity << ' ' << appleLabel(quantity) << '\n';
}

void printStatus(bool restockRequired)
{
    std::cout << "Status: " << (restockRequired ? "restock required" : "stock level healthy") << '\n';
}

void printCrates(int crates)
{
    std::cout << "Crates to order: " << crates << '\n';
}
