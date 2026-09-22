/*
Lesson 7.8 - Why (non-const) global variables are evil
LearnCpp: https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/
Tasks:
- Implement remainingStock using only its stock and shipped parameters.
- Keep startingStock 18 and shipped 5 as local constexpr values in main.
- Print the calculated result and a reusable second call with arguments 9 and 2.
Concept:
- Explicit inputs and a return value avoid hidden mutable global state.
Constraints:
- Do not add a mutable global or static local variable and do not read stdin.
Exact expected output:
Remaining stock: 13
Sample remaining: 7
Completion checklist:
- The function returns stock - shipped and both outputs come from function calls.
- The C++20 program builds warning-free and passes ./course check 7.8.
*/
#include <iostream>

int remainingStock(int stock, int shipped)
{
    return stock + shipped; // TODO: Return the remaining quantity.
}

int main()
{
    constexpr int startingStock{ 18 };
    constexpr int shipped{ 5 };
    const int remaining{ remainingStock(startingStock, shipped) };

    std::cout << "Remaining stock: " << remaining << '\n';
    std::cout << "Sample remaining: " << remainingStock(9, 2) << '\n';
    return 0;
}
