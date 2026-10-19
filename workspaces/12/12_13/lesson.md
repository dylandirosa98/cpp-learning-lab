# 12.13: In and out parameters

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Input parameters supply data; output parameters receive calculated results; in/out parameters do both. Non-const references can represent output destinations, but the contract must specify what happens on failure.

Validate before changing any output when failure promises to preserve state. This makes callers able to inspect the status without recovering partially updated results.

## Your mission

Implement divideWithRemainder(numerator,denominator,quotient,remainder). If denominator is zero, return false and leave both output integers unchanged. Otherwise write the C++ integer quotient and remainder, and return true. Output references refer to distinct objects. Inputs are small, avoiding division overflow.

## Expected behavior

- `17 / 5 -> quotient=3, remainder=2, true`
- `-17 / 5 -> quotient=-3, remainder=-2, true`
- `denominator=0 -> false; outputs unchanged`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.13`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: In and out parameters](https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/)
