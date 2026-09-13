/*
Lesson 2.2: Function return values (value-returning functions)
LearnCpp: https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/

What you are practicing:
- Returning an int value to a function's caller.
- Using returned values to initialize variables and calculate another value.
- Keeping calculation separate from console output.

Before coding:
- Read the three counting functions and then main().
- The current return values are placeholders, so the starter compiles but gives
  the wrong report.
- Only replace the three TODOs and their placeholder return statements.

Exact numbered instructions for every function:
1. countLiftedShingles(): Return the recorded lifted-shingle count, 7.
2. countLooseFasteners(): Return the recorded loose-fastener count, 4.
3. countTotalDefects(): Call both counting functions, add the two returned
   values, and return that sum. Do not repeat the recorded counts here.
4. main(): Keep the three function results stored in lifted, loose, and total;
   print the existing labeled report; then return success.

Language-neutral pseudocode for each TODO:
- countLiftedShingles TODO:
  RETURN 7
- countLooseFasteners TODO:
  RETURN 4
- countTotalDefects TODO:
  SET lifted result to CALL countLiftedShingles
  SET loose result to CALL countLooseFasteners
  RETURN lifted result plus loose result

Input/output examples:
- countLiftedShingles receives no input and returns 7.
- countLooseFasteners receives no input and returns 4.
- countTotalDefects receives no input and returns 11.

Constraints:
- Keep every function name, int return type, and empty parameter list unchanged.
- Calculate the total by calling both counting functions.
- Keep output in main(); the counting functions return values but print nothing.
- Use std::cout for output. Do not use unqualified cout.
- Do not add using namespace std or a using declaration for cout.

Exact expected output:
Lifted shingles: 7
Loose fasteners: 4
Total defects: 11

Completion checklist:
- [ ] All three placeholder returns are replaced.
- [ ] countTotalDefects() calls both smaller counting functions.
- [ ] The text, values, spacing, and line breaks match exactly.
- [ ] No function signature was changed.

Checker command:
./course check 2.2
*/

#include <iostream>

int countLiftedShingles()
{
    // TODO: Replace the placeholder with the recorded count 7 and return it.
    return 0;
}

int countLooseFasteners()
{
    // TODO: Replace the placeholder with the recorded count 4 and return it.
    return 0;
}

int countTotalDefects()
{
    // TODO: Replace the placeholder with the sum returned by calls to both
    // counting functions; do not repeat their recorded numeric counts here.
    return 0;
}

int main()
{
    int lifted{countLiftedShingles()};
    int loose{countLooseFasteners()};
    int total{countTotalDefects()};

    std::cout << "Lifted shingles: " << lifted << '\n';
    std::cout << "Loose fasteners: " << loose << '\n';
    std::cout << "Total defects: " << total << '\n';

    return 0;
}
