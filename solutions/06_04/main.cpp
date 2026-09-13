#include <iostream>

int main()
{
    int counter{ 5 };

    int postfixValue{ counter++ };
    int prefixValue{ ++counter };
    --counter;

    std::cout << "Postfix produced: " << postfixValue << '\n';
    std::cout << "Prefix produced: " << prefixValue << '\n';
    std::cout << "Final counter: " << counter << '\n';
    return 0;
}
