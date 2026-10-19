# 9.4: Detecting and handling errors

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

**Route:** Learn → predict → code → run tests → explain → submit.

This experimental chapter uses a guided, challenge-first lesson format. Everything needed for the mission is in this folder; external reading is optional enrichment.

## Learn: choose an error policy deliberately

Separate detection, reporting, and recovery. A calculation function can report failure to its caller without printing to a terminal or exiting the process. The user interface can then choose to retry, explain the failure, or stop. An assertion, sentinel, optional result, and exception are different tools with different contracts; exceptions are not required here.

## Worked example: an unambiguous sentinel

With nonnegative values and positive divisors, a valid remainder is between zero and divisor minus one. Therefore -1 cannot be a valid successful result. That makes it a usable error sentinel here. In a function where -1 could be a valid answer, the same design would be ambiguous.

## Validate before the dangerous operation

Remainder by zero is not a recoverable result you can inspect afterward. Check the divisor before evaluating %. Validate all other domain restrictions before returning the computed value. Avoid returning a normal-looking zero for errors, because zero is a perfectly valid remainder.

## Reflect

Who should decide whether an error message is displayed? Why would changing the successful result domain potentially invalidate the -1 sentinel design?

## Your mission

Implement safeRemainder(value, divisor). For value >= 0 and divisor > 0, return value % divisor. Otherwise return -1 without performing remainder. The sentinel is unambiguous because successful remainders are nonnegative. Do not halt the process or print an error.

## Expected behavior

- `safeRemainder(17,5) -> 2`
- `safeRemainder(0,5) -> 0`
- `safeRemainder(4,0) -> -1`
- `safeRemainder(-4,3) -> -1`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 9.4`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Detecting and handling errors](https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/)
