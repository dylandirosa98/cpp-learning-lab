/*
Lesson 7.4 - Introduction to global variables
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/
Practice:
- Define fixed shared data at global scope inside a user-defined namespace.
- Access that global explicitly from more than one function.
Tasks:
1. Define constexpr int capacity as 40 inside namespace Warehouse.
2. Return Warehouse::capacity - stored from availableSpace.
3. Print the capacity through its qualified name and print the calculated space.
Function responsibilities:
- availableSpace calculates against the global warehouse capacity.
- main owns the fixed stored count and reports the capacity calculation.
Constraints:
- capacity must be a namespaced constexpr global, not a local or mutable global.
- Keep the exercise deterministic and do not read stdin or hard-code calculated results.
Exact expected output:
Warehouse capacity: 40
Items stored: 27
Available space: 13
Completion checklist:
- Warehouse::capacity is defined outside every function.
- Both availableSpace and main access capacity by its qualified name.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 7.4
*/
#include <iostream>

// TODO: Define namespace Warehouse and its constexpr capacity here at global scope.
namespace Warehouse {
constexpr int capacity{40};
}

int availableSpace(int stored) {
    // TODO: Subtract stored from the namespaced global capacity.

    return Warehouse::capacity - stored;
}

int main() {
    constexpr int stored{27};

    // TODO: Print Warehouse::capacity instead of a placeholder.
    std::cout << "Warehouse capacity: " << Warehouse::capacity << '\n';
    std::cout << "Items stored: " << stored << '\n';
    std::cout << "Available space: " << availableSpace(stored) << '\n';
    return 0;
}
