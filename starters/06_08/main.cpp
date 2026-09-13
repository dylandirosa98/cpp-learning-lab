/*
Lesson 6.8 - Logical operators
LearnCpp: https://www.learncpp.com/cpp-tutorial/logical-operators/
Practice:
- Combine mandatory, alternative, and negated boolean requirements.
- Group a mixed logical policy so its intent is visible.
Tasks:
1. Require hasBadge with logical AND.
2. Accept either isStaff or hasAppointment in a parenthesized OR expression.
3. Also require that !isSuspended is true.
4. Exercise all three supplied scenarios and print boolalpha results.
Function responsibilities:
- canEnter applies the access policy without input or output.
- main invokes that policy for fixed scenarios and reports each result.
Constraints:
- Use &&, ||, and !; do not substitute bitwise operators.
- Do not special-case scenarios or hard-code expected booleans.
Exact expected output:
Appointed visitor: true
Staff without badge: false
Suspended staff: false
Completion checklist:
- The badge and suspension rules are mandatory.
- Staff status or an appointment satisfies the grouped alternative requirement.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 6.8
*/
#include <iostream>

bool canEnter(bool hasBadge, bool isStaff, bool hasAppointment, bool isSuspended)
{
    // TODO: Combine all four parameters into the stated access policy.
    return hasBadge || isStaff || hasAppointment || isSuspended;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Appointed visitor: " << canEnter(true, false, true, false) << '\n';
    std::cout << "Staff without badge: " << canEnter(false, true, false, false) << '\n';
    std::cout << "Suspended staff: " << canEnter(true, true, false, true) << '\n';
    return 0;
}
