#include <iostream>

int countLiftedShingles()
{
    return 7;
}

int countLooseFasteners()
{
    return 4;
}

int countTotalDefects()
{
    return countLiftedShingles() + countLooseFasteners();
}

int main()
{
    int lifted{countLiftedShingles()};
    int loose{countLooseFasteners()};
    int total{countTotalDefects()};

    std::cout << "Lifted shingles: " << lifted << '\n';
    std::cout << "Loose fasteners: " << loose << '\n';
    std::cout << "Total defects: " << total << '\n';

    return 0;
}
