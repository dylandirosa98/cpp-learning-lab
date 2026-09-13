#include <iostream>
#include <string>
#include <string_view>

void printLabel(std::string_view label)
{
    std::cout << "Label: " << label << '\n';
}

int main()
{
    printLabel("literal");

    std::string owned{ "owned string" };
    printLabel(owned);

    std::string_view viewed{ "existing view" };
    printLabel(viewed);
    return 0;
}
