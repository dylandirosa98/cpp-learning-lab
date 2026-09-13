/*
Lesson 2.8 - Programs with multiple code files
LearnCpp: https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/

What you are practicing:
- Defining a function in a separate translation unit for main.cpp to call.
- Converting a calculated minute total to whole hours.

Required files, function, and observable behavior:
- crew.cpp defines int requiredCrewHours(int sections, int minutesPerSection).
- main.cpp contains the matching declaration and calls it with 8 and 45.
- This function returns 6 for those sample inputs and performs no output.

Formula and example:
- whole crew hours = (sections * minutesPerSection) / 60 using integer division
- requiredCrewHours(8, 45) returns 6.

Constraints:
- Keep this definition in crew.cpp; do not include main.cpp.
- Keep the exact int signature used by main.cpp.
- Standard-library names must be explicitly qualified with std:: if any are
  added; this calculation function needs no standard-library facilities.

Expected output from the complete program:
Required crew time: 6 hours

Completion checklist:
- The function multiplies the two inputs before converting to hours.
- The result uses whole-number division and is returned without printing.
- The complete two-file program prints the exact line above.

Checker command: ./course check 2.8
*/
int requiredCrewHours(int sections, int minutesPerSection)
{
    // TODO: Return total section minutes converted to whole hours using 60.
    return sections - minutesPerSection;
}
