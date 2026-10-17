#include <iostream>

void printComparison(int left, int right)
{
    if (left == right)
    {
        std::cout << left << " equals " << right << '\n';
    }
    else if (left < right)
    {
        std::cout << left << " is less than " << right << '\n';
    }
    else
    {
        std::cout << left << " is greater than " << right << '\n';
    }
}

int main()
{
    printComparison(3, 3);
    printComparison(2, 5);
    printComparison(9, 4);
    return 0;
}
