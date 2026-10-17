/*
Lesson 2.1: Introduction to functions
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-functions/

What you are practicing:
- Defining void functions before the code that calls them.
- Calling one function from another and tracing the order of execution.
- Calling small functions to build one larger operation.

Before coding:
- Read all four functions from top to bottom.
- Notice that main() is already complete. Only replace the three TODOs.
- Each inspection message must be followed by a newline.

Exact numbered instructions for every function:
1. checkFlashing(): Write exactly "Flashing secure" followed by a newline.
2. checkVent(): Write exactly "Vent clear" followed by a newline.
3. inspectRoof(): Write exactly "Roof inspection started" and a newline,
   call checkFlashing(), call checkVent(), then write exactly
   "Roof inspection complete" and a newline.
4. main(): Keep the existing dispatch output, inspectRoof() call, return
   output, and success return in their current order.

Language-neutral pseudocode for each TODO:
- checkFlashing TODO:
  OUTPUT "Flashing secure"
- checkVent TODO:
  OUTPUT "Vent clear"
- inspectRoof TODO:
  OUTPUT "Roof inspection started"
  CALL checkFlashing
  CALL checkVent
  OUTPUT "Roof inspection complete"

Constraints:
- Keep every function name, return type, parameter list, and order unchanged.
- Keep all three inspection function definitions above main().
- Use std::cout for output. Do not use unqualified cout.
- Do not add using namespace std or a using declaration for cout.
- Do not move the inspection output statements into main().

Exact expected output:
Crew dispatched
Roof inspection started
Flashing secure
Vent clear
Roof inspection complete
Crew returned

Completion checklist:
- [ ] All three TODOs are replaced with code.
- [ ] checkFlashing() runs before checkVent().
- [ ] The text, capitalization, spacing, and line breaks match exactly.
- [ ] No function signature was changed.

Checker command:
./course check 2.1
*/

#include <iostream>

void checkFlashing()
{
    std::cout << "Flashing secure" << std::endl;
}

void checkVent()
{
    std::cout << "Vent clear\n";
}

void inspectRoof()
{
    std::cout << "Roof inspection started" << std::endl;
    checkFlashing();
    checkVent();
    std::cout << "Roof inspection complete" << std::endl;
}

int main()
{
    std::cout << "Crew dispatched\n";
    inspectRoof();
    std::cout << "Crew returned\n";

    return 0;
}
