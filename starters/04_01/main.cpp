/*
Lesson 4.1 - Introduction to fundamental data types
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-fundamental-data-types/
What is practiced:
- Match a two-state condition, one character, and a fractional measurement to
  the supplied bool, char, and double fundamental types.
- Control how a Boolean object is presented without replacing it with text.
Required repair:
1. Read the three stated record values before editing the placeholders.
2. Keep systemOnline as bool, zoneCode as char, and targetVoltage as double.
3. Replace each placeholder initializer with the value described below.
4. Build and compare all punctuation, spacing, and value formatting exactly.
Record values:
- The system is online.
- The zone code is the single character C.
- The target voltage is 12.5.
File responsibilities:
- main owns the fixed typed record and presents its three fields.
Constraints:
- Keep the three variable names and fundamental types.
- Derive output from the variables; do not hard-code completed output lines.
- Use no input and do not import the std namespace.
Exact expected output:
System online: true
Zone code: C
Target voltage: 12.5
Completion checklist:
- Each initializer uses a literal appropriate for the object's type.
- The bool prints as true rather than 1.
- The C++20 build is warning-free and output matches exactly.
Run from project root: ./course check 4.1
*/
#include <iostream>

int main()
{
    bool systemOnline{ false };
    char zoneCode{ '?' };
    double targetVoltage{ 0.0 };

    std::cout << std::boolalpha;
    std::cout << "System online: " << systemOnline << '\n';
    std::cout << "Zone code: " << zoneCode << '\n';
    std::cout << "Target voltage: " << targetVoltage << '\n';
    return 0;
}
