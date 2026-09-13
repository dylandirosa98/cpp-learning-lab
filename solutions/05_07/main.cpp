#include <iostream>
#include <string>

int main()
{
    std::string label{ "C++" };
    label = "C++ Lab";
    label += " 2026";

    std::cout << "Label: " << label << '\n';
    std::cout << "ASCII length: " << label.length() << '\n';
    return 0;
}
