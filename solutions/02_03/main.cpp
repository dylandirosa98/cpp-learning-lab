#include <iostream>

void printTagHeader()
{
    std::cout << "SAFETY TAG\n";
}

void printHarnessStatus()
{
    std::cout << "Harness: inspected\n";
}

void printTagFooter()
{
    std::cout << "Status: ready\n";
}

int main()
{
    printTagHeader();
    printHarnessStatus();
    printTagFooter();

    return 0;
}
