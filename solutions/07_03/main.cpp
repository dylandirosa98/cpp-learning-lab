#include <iostream>

int main()
{
    int itemsRemaining{ 9 };
    std::cout << "Starting items: " << itemsRemaining << '\n';

    {
        const int packedItems{ 4 };
        itemsRemaining -= packedItems;
        std::cout << "Packed in inner scope: " << packedItems << '\n';
    }

    std::cout << "Items after block: " << itemsRemaining << '\n';
    return 0;
}
