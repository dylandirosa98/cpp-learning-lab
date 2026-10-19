# 10.x: Chapter 10 summary and quiz

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Combine range validation, domain aliases, and deliberate conversion points into one small API. Validate inputs before arithmetic and keep integer money calculations wide enough.

Rounding at the wrong stage changes a bill: discounting each item then multiplying is not necessarily the same as discounting the full subtotal once. The contract specifies the latter.

## Your mission

Implement invoiceTotal(unitPrice, quantity, discountPercent) in integer Cents and currencyUnits(cents) as double major units. Invoice total is unitPrice*quantity*(100-discountPercent)/100, truncating fractional cents only at the end. Negative unitPrice/quantity or discount outside [0,100] returns -1; zero quantity is valid. Inputs are unitPrice <= 1000000 and quantity <= 1000. currencyUnits divides any supplied signed cents by 100.0.

## Expected behavior

- `invoiceTotal(999,3,10) -> 2697`
- `invoiceTotal(999,0,10) -> 0`
- `currencyUnits(125) -> 1.25`
- `currencyUnits(-50) -> -0.5`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.x`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Chapter 10 summary and quiz](https://www.learncpp.com/cpp-tutorial/chapter-10-summary-and-quiz/)
