/*
Lesson 2.3: Void functions (non-value returning functions)
LearnCpp: https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/

What you are practicing:
- Using void for a function that performs output but returns no value.
- Calling void functions as standalone statements.
- Letting a void function finish at its closing brace.

Before coding:
- Read the three printing functions and then main().
- Notice that main() already calls the functions in the required order.
- Only replace the three TODOs. Do not add return statements to void functions.

Exact numbered instructions for every function:
1. printTagHeader(): Write exactly "SAFETY TAG" followed by a newline.
2. printHarnessStatus(): Write exactly "Harness: inspected" followed by a
   newline.
3. printTagFooter(): Write exactly "Status: ready" followed by a newline.
4. main(): Keep the existing three standalone calls in header, harness,
   footer order, and keep the success return. Do not add output here.

Language-neutral pseudocode for each TODO:
- printTagHeader TODO:
  OUTPUT "SAFETY TAG"
- printHarnessStatus TODO:
  OUTPUT "Harness: inspected"
- printTagFooter TODO:
  OUTPUT "Status: ready"

Constraints:
- Keep all three printing functions void and parameterless.
- Do not return a value or add an empty return to a printing function.
- Keep every output operation inside its matching printing function.
- Use std::cout for output. Do not use unqualified cout.
- Do not add using namespace std or a using declaration for cout.

Exact expected output:
SAFETY TAG
Harness: inspected
Status: ready

Completion checklist:
- [ ] All three TODOs are replaced with output code.
- [ ] main() contains calls but no direct output.
- [ ] The text, capitalization, punctuation, and line breaks match exactly.
- [ ] No void function contains a return statement.

Checker command:
./course check 2.3
*/

#include <iostream>

void printTagHeader()
{
    // TODO: Use std::cout to write exactly "SAFETY TAG" and a newline.
}

void printHarnessStatus()
{
    // TODO: Use std::cout to write exactly "Harness: inspected" and a newline.
}

void printTagFooter()
{
    // TODO: Use std::cout to write exactly "Status: ready" and a newline.
}

int main()
{
    printTagHeader();
    printHarnessStatus();
    printTagFooter();

    return 0;
}
