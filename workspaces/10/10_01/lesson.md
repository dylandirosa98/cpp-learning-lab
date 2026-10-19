# 10.1: Implicit type conversion

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

C++ can convert values automatically when initializing objects, passing arguments, returning values, or mixing types in expressions. The destination type does not retroactively change how an earlier subexpression was evaluated.

Making an operand floating-point before division preserves a fractional result; converting an already-truncated integer quotient cannot restore the lost fraction.

## Your mission

Implement metersFromCentimeters(cm). Return centimeters divided by 100 as a double, preserving fractions. Negative distances return -1.0. Test distances are at most one million centimeters. Think about when conversion happens, not just the return type.

## Expected behavior

- `metersFromCentimeters(125) -> 1.25`
- `metersFromCentimeters(1) -> 0.01`
- `metersFromCentimeters(-1) -> -1.0`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.1`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Implicit type conversion](https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/)
