#include <iostream>

int main()
{
    const int trays{ 3 };
    const int rowsPerTray{ 4 };
    const int muffinsPerRow{ 6 };
    const int bakedMuffins{ trays * rowsPerTray * muffinsPerRow };
    const int reservedMuffins{ 2 * muffinsPerRow };
    const int packedMuffins{ bakedMuffins - reservedMuffins };

    std::cout << "Baked muffins: " << bakedMuffins << '\n';
    std::cout << "Packed muffins: " << packedMuffins << '\n';
    return 0;
}
