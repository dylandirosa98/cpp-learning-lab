/*
Lesson 5.8 - Introduction to std::string_view
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/
Practice:
- Accept several string source types through one cheap read-only parameter.
- Avoid copying owned text merely to inspect and print it.
Task:
1. Add the standard header that declares std::string_view.
2. Change printLabel's by-value std::string parameter to std::string_view.
3. Keep printLabel read-only and preserve its single output statement.
4. Retain the literal, std::string, and std::string_view arguments.
5. Build and verify that all calls produce their ordered report lines.
Function responsibility:
- printLabel observes and prints text without taking ownership.
- main demonstrates the three supported argument forms.
Constraints:
- Pass std::string_view by value; do not use std::string or a reference parameter.
- Do not replace the three calls with direct output statements.
Exact expected output:
Label: literal
Label: owned string
Label: existing view
Completion checklist:
- printLabel has exactly one std::string_view parameter.
- No string data is modified and all argument forms compile.
- The deterministic program builds warning-free as C++20.
Run from project root: ./course check 5.8
*/
#include <iostream>
#include <string>

void printLabel(std::string label)
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
