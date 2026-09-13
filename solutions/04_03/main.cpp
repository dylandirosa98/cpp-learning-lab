#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    std::cout << "char is one byte: " << (sizeof(char) == 1) << '\n';
    std::cout << "short no larger than int: " << (sizeof(short) <= sizeof(int)) << '\n';
    std::cout << "int no larger than long: " << (sizeof(int) <= sizeof(long)) << '\n';
    std::cout << "long no larger than long long: " << (sizeof(long) <= sizeof(long long)) << '\n';
    return 0;
}
