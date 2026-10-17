/*
Lesson 6.4 - Increment/decrement operators, and side effects
LearnCpp: https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
Practice:
- Observe the distinct values yielded by postfix and prefix increment.
- Sequence every mutation in a simple, readable statement.
Tasks:
1. Initialize postfixValue from counter++.
2. Initialize prefixValue from ++counter.
3. Apply --counter as a separate statement.
4. Print the captured values and final counter exactly.
Function responsibility:
- main owns one ticket counter and demonstrates its three ordered side effects.
Constraints:
- Do not combine multiple increments in one expression or hard-code results.
- Preserve the operation order and do not add input.
Exact expected output:
Postfix produced: 5
Prefix produced: 7
Final counter: 6
Completion checklist:
- Postfix yields 5 before changing counter to 6.
- Prefix changes counter to 7 before yielding 7, then decrement leaves 6.
- The C++20 program builds warning-free and output matches exactly.
Run from project root: ./course check 6.4
*/
#include <iostream>

int main()
{
    int counter{ 5 };

    int postfixValue{ counter++ }; // TODO: Capture the value from counter++.
    int prefixValue{ ++counter }; // TODO: Capture the value from ++counter.
    --counter;// TODO: Decrement counter once in its own statement.

    std::cout << "Postfix produced: " << postfixValue << '\n';
    std::cout << "Prefix produced: " << prefixValue << '\n';
    std::cout << "Final counter: " << counter << '\n';
    return 0;
}
