#include <iostream>

int main()
{
    const int cartonsPerShelf{ 6 };
    const int shelfCount{ 5 };
    const int totalCartons{ cartonsPerShelf * shelfCount };

    std::cout << "Cartons per shelf: " << cartonsPerShelf << '\n';
    std::cout << "Shelf count: " << shelfCount << '\n';
    std::cout << "Total cartons: " << totalCartons << '\n';
    return 0;
}
