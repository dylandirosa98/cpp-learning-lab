#include <iostream>

int statusCode{ 100 };

int main()
{
    int statusCode{ 7 };

    ++statusCode;
    --(::statusCode);

    std::cout << "Local status: " << statusCode << '\n';
    std::cout << "Global status: " << ::statusCode << '\n';
    return 0;
}
