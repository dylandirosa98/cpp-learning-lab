/*
Lesson 4.5 - Unsigned integers, and why to avoid them
LearnCpp: https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
What is practiced:
- Diagnose mixed signed/unsigned quantity arithmetic and comparisons.
- Prefer signed quantities when subtraction can have a negative result.
Required repair:
1. Build the starter and read all signedness or narrowing diagnostics.
2. Identify which quantity type forces available - requested to be unsigned.
3. Give both inventory quantities the same preferred signed type.
4. Rebuild without adding casts, then verify arithmetic and comparison output.
Calculation contract:
- Two units are available and three are requested.
- The mathematical balance is -1 and the request cannot be fulfilled.
File responsibilities:
- main owns fixed quantities, calculates the balance and decision, and prints.
Constraints:
- Preserve both fixed values and the supplied - and >= expressions.
- Remove the inappropriate unsigned quantity type; do not mask it with a cast.
- Do not hard-code results, use input, or import the std namespace.
Exact expected output:
Inventory balance: -1
Can fulfill: false
Completion checklist:
- Both ordinary quantities use signed int.
- No signed/unsigned conversion is involved in either expression.
- The C++20 build is warning-free and both lines match exactly.
Run from project root: ./course check 4.5
*/
#include <iostream>

int main()
{
    unsigned int available{ 2 };
    unsigned int requested{ 3 };
    unsigned int balance{ available - requested };
    bool canFulfill{ available >= requested };

    std::cout << "Inventory balance: " << balance << '\n';
    std::cout << "Can fulfill: " << std::boolalpha << canFulfill << '\n';
    return 0;
}
