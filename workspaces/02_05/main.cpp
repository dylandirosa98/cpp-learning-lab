/*
Lesson 2.5: Introduction to local scope
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/

What you are practicing:
- Using a value parameter as a function-local copy of an argument.
- Declaring a local variable where it is needed.
- Seeing that same-named variables in different functions are independent.

Before coding:
- calibrateReading() receives its own copied parameter named reading.
- main() owns a different local variable that is also named reading.
- Only replace the TODO and the placeholder behavior in calibrateReading().

Exact numbered instructions for every function:
1. calibrateReading(): Declare a local int named offset initialized to 3.
   Subtract offset from the copied reading parameter, then return that adjusted
   parameter.
2. main(): Keep its reading initialized to 18, print it, pass it to
   calibrateReading(), store the result in adjusted, print adjusted, print
   main's unchanged reading again, and return success.

Language-neutral pseudocode for each TODO:
- calibrateReading TODO:
  SET local offset to 3
  DECREASE copied reading by offset
  RETURN copied reading

Input/output examples:
- calibrateReading with 18 returns 15.
- calibrateReading with 10 returns 7.
- calibrateReading with 3 returns 0.

Constraints:
- Keep the calibrateReading(int reading) signature unchanged.
- Name the local integer offset and initialize it to 3 inside that function.
- Adjust the parameter copy; do not create or modify a global variable.
- Keep main's separate reading initialized to 18.
- Use std::cout for output. Do not use unqualified cout.
- Do not add using namespace std or a using declaration for cout.

Exact expected output:
Raw reading: 18
Adjusted reading: 15
Raw reading after call: 18

Completion checklist:
- [ ] offset is local to calibrateReading() and starts at 3.
- [ ] The copied parameter is adjusted and returned.
- [ ] main's reading still prints as 18 after the call.
- [ ] The labels, values, spacing, and line breaks match exactly.

Checker command:
./course check 2.5
*/

#include <iostream>

int calibrateReading(int reading)
{
    int offset{3};
    reading -= offset;
    return reading;
}

int main()
{
    int reading{18};
    std::cout << "Raw reading: " << reading << '\n';

    int adjusted{calibrateReading(reading)};
    std::cout << "Adjusted reading: " << adjusted << '\n';
    std::cout << "Raw reading after call: " << reading << '\n';

    return 0;
}
