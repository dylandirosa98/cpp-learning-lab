/*
Lesson 2.7 - Forward declarations and definitions
LearnCpp: https://www.learncpp.com/cpp-tutorial/forward-declarations/

What you are practicing:
- Declaring a function before its first use and defining it later.
- Keeping a declaration and definition's types identical.

Required function and observable behavior:
- main.cpp must declare int roofLoad(int panels, int kilogramsPerPanel) before
  main() and define that exact function after main().
- main() must call roofLoad(12, 12) and print the returned load.
- roofLoad() returns the combined load and performs no output.

Formula and example:
- total load = panels * kilogramsPerPanel
- roofLoad(12, 12) returns 144.

Constraints:
- The forward declaration has no body and ends with a semicolon.
- Keep the declaration and definition signatures identical.
- Qualify standard-library names explicitly with std::, including std::cout;
  do not use a using-directive.

Expected output:
Calculated roof load: 144 kg

Completion checklist:
- The matching prototype appears before main().
- The definition remains after main() and returns the formula result.
- The program builds and prints the exact line above.

Checker command: ./course check 2.7
*/
#include <iostream>

// TODO: Add the matching roofLoad prototype before main so its call is declared.
int main()
{
    std::cout << "Calculated roof load: " << roofLoad(12, 12) << " kg\n";
    return 0;
}

int roofLoad(int panels, int kilogramsPerPanel)
{
    return panels * kilogramsPerPanel;
}
