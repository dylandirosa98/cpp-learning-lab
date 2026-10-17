/*
Lesson 2.9 - Naming collisions and an introduction to namespaces
LearnCpp: https://www.learncpp.com/cpp-tutorial/naming-collisions-and-an-introduction-to-namespaces/

What you are practicing:
- Distinguishing same-named identifiers that belong to different namespaces.
- Selecting a standard-library name with the scope-resolution operator.

Required function and observable behavior:
- main.cpp defines the global function int cout(), which returns 27.
- main() calls the global cout() function for the open-section count.
- main() uses the standard output stream to print the exact report line.

Feature condition and example:
- The unqualified name cout() selects the global function because it is a call.
- The output stream must be selected from namespace std to avoid the collision.
- cout() returns 27, producing the report shown below.

Constraints:
- Keep the function name cout and its int signature.
- Use explicit std::cout qualification; do not use a using-directive.
- Print one line ending with a newline.

Expected output:
Open roof sections: 27

Completion checklist:
- The global cout() function still returns the required count.
- The output expression explicitly selects std::cout and calls cout().
- The program builds without a name collision and prints the exact line above.

Checker command: ./course check 2.9
*/
#include <iostream>

int cout()
{
    return 27;
}

int main()
{
    // TODO: Select the standard namespace's output stream while calling global cout().
    std::cout << "Open roof sections: " << cout() << '\n';
    return 0;
}
