/*
Lesson 4.9 - Boolean values
LearnCpp: https://www.learncpp.com/cpp-tutorial/boolean-values/
Practice:
- Let a comparison expression produce a bool result directly.
- Use std::boolalpha for readable true and false output.
Task:
1. Keep isWithinCapacity as a bool-returning predicate.
2. Replace the overly strict comparison in its return statement.
3. Return true when packages is less than or equal to capacity.
4. Confirm that the supplied calls exercise spare, exact, and excess capacity.
Function responsibility:
- isWithinCapacity answers one capacity question without printing.
 - main prints the three deterministic observations.
Constraints:
- Do not use an if statement, hard-code true or false, or change the calls.
- Keep std::boolalpha and return a comparison expression directly.
Exact expected output:
Capacity 8 of 10: true
Capacity 10 of 10: true
Capacity 12 of 10: false
Completion checklist:
- Spare capacity and exact capacity would both be accepted.
- Excess packages are rejected and bools print as words.
- The program builds warning-free as C++20.
Run from project root: ./course check 4.9
*/
#include <iostream>

bool isWithinCapacity(int packages, int capacity)
{
    return packages == capacity;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Capacity 8 of 10: " << isWithinCapacity(8, 10) << '\n';
    std::cout << "Capacity 10 of 10: " << isWithinCapacity(10, 10) << '\n';
    std::cout << "Capacity 12 of 10: " << isWithinCapacity(12, 10) << '\n';
    return 0;
}
