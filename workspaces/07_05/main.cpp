/*
Lesson 7.5 - Variable shadowing (name hiding)
LearnCpp: https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/
Practice:
- Observe how an inner declaration hides an outer declaration with the same name.
- Use the unary scope resolution operator to select a hidden global explicitly.
Tasks:
1. Increment the local statusCode through its unqualified name.
2. Decrement the global statusCode through ::statusCode.
3. Print the local value first and the explicitly selected global value second.
Function responsibility:
- main performs one controlled demonstration using the supplied global and local objects.
Constraints:
- Preserve both statusCode declarations to demonstrate shadowing deliberately.
- Do not assign the expected final values directly or read stdin.
Exact expected output:
Local status: 8
Global status: 99
Completion checklist:
- The unqualified increment affects only the local statusCode.
- The qualified decrement and output affect only the global statusCode.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 7.5
*/
#include <iostream>

int statusCode{100};

int main() {
    int statusCode{7};

    // TODO: Increment the local and decrement the hidden global explicitly.
    ++statusCode;
    --(::statusCode);

    std::cout << "Local status: " << statusCode << '\n';
    std::cout << "Global status: " << ::statusCode << '\n'; // TODO: Select the global.
    return 0;
}
