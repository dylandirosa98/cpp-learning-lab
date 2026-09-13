/*
Lesson 5.7 - Introduction to std::string
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
Practice:
- Store text in an owning, mutable std::string.
- Replace, append, and measure deterministic ASCII text.
Task:
1. Keep label initialized with the ASCII text C++.
2. Make label mutable so later operations are valid.
3. Replace its contents with C++ Lab using assignment.
4. Append a space followed by 2026 with operator+=.
5. Print the final label and call length() for the second result.
Function responsibility:
- main owns and modifies the label before reporting its final state.
Constraints:
- Use std::string, assignment, operator+=, and label.length().
- Do not hard-code C++ Lab 2026 or 12 directly in output statements.
Exact expected output:
Label: C++ Lab 2026
ASCII length: 12
Completion checklist:
- label owns its storage and remains mutable.
- Its final value is assembled by replacement followed by append.
- The ASCII length is calculated and the C++20 build is warning-free.
Run from project root: ./course check 5.7
*/
#include <iostream>
#include <string>

int main()
{
    const std::string label{ "C++" };
    label = "C++ Lab";
    label = " 2026";

    std::cout << "Label: " << label << '\n';
    std::cout << "ASCII length: " << 12 << '\n';
    return 0;
}
