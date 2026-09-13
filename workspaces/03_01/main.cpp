/*
Lesson 3.1 - Syntax and semantic errors
LearnCpp: https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
What is practiced:
- Separate syntax errors, compile-time semantic errors, and runtime semantic
  errors while repairing one intentionally broken program.
- Work from the first useful compiler diagnostic and validate behavior after
  compilation succeeds.
Explicit expected behavior:
- Six rows with eight fasteners per row produce 48 installed fasteners.
- Adding five spare fasteners produces 53 available fasteners.
Debugging and repair procedure:
1. Build this untouched file and record the first compiler diagnostic.
2. Repair one diagnostic, rebuild, and repeat until the build is warning-free.
3. Run the program and compare both values with the expected output below.
4. If a value is wrong, break at the start of installedFasteners(), inspect
   rows and fastenersPerRow, then step to and observe its returned value.
5. Make the smallest repair that restores the stated calculation and rerun.
File and function responsibilities:
- installedFasteners calculates the installed quantity from two parameters.
- printInventory owns both output lines and adds installed and spare counts.
- main supplies fixed inputs, stores results, coordinates output, and returns
  success.
Constraints:
- Keep all function signatures and fixed inputs unchanged.
- Derive displayed numbers from function results; do not hard-code them.
- Use explicit std:: qualification and do not add using namespace std.
Exact expected output:
Installed fasteners: 48
Fasteners available: 53
Completion checklist:
- The program compiles under C++20 with no warnings.
- Each compiler diagnostic was considered from earliest to latest.
- Both calculations and both output lines match the contract exactly.
- The final source contains no hard-coded expected result.
Run from project root: ./course check 3.1
*/
#include <iostream>

int installedFasteners(int rows, int fastenersPerRow)
{
    return rows * fastenersPerRow;
}

void printInventory(int installed, int spare)
{
    std::cout << "Installed fasteners: " << installed << '\n';
    std::cout << "Fasteners available: " << installed + spare << '\n';
}

int main()
{
    int installed{ installedFasteners(6, 8) };
    int spare{ 5 };
    printInventory(installed, spare);
    return 0;
}
