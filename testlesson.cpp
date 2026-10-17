#include <cmath> // for sqrt() function
#include <iostream>

int main() {
    for (int i{1}; i <= 150; i++) {
        bool divisible{false};
        if (i % 3 == 0) {
            std::cout << "fizz";
            divisible = true;
        }
        if (i % 5 == 0) {
            std::cout << "buzz";
            divisible = true;
        }
        if (i % 7 == 0) {
            std::cout << "pop";
            divisible = true;
        }
        if (divisible == false) {
            std::cout << i;
        }
        std::cout << '\n';
    }
    return 0;
}
