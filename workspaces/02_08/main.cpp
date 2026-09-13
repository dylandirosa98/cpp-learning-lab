/*
Lesson 2.8 - Programs with multiple code files
LearnCpp: https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/

What you are practicing:
- Calling a function whose definition is compiled from another source file.
- Sharing a matching declaration without including an implementation file.

Required files, function, and observable behavior:
- main.cpp declares int requiredCrewHours(int sections, int minutesPerSection)
  and calls requiredCrewHours(8, 45).
- crew.cpp defines that exact function and returns the whole crew hours.
- main.cpp prints the returned value as the required report line.

Formula and example:
- whole crew hours = (sections * minutesPerSection) / 60 using integer division
- requiredCrewHours(8, 45) returns 6.

Constraints:
- Keep the declaration in main.cpp and the definition in crew.cpp identical.
- Compile both source files; do not include either .cpp file from the other.
- Qualify standard-library names explicitly with std::, including std::cout;
  do not use a using-directive.

Expected output:
Required crew time: 6 hours

Completion checklist:
- main.cpp has the declaration and required call.
- crew.cpp implements the whole-hour formula.
- Both files link and the program prints the exact line above.

Checker command: ./course check 2.8
*/
#include <iostream>

int requiredCrewHours(int sections, int minutesPerSection);

int main()
{
    std::cout << "Required crew time: " << requiredCrewHours(8, 45) << " hours\n";
    return 0;
}
