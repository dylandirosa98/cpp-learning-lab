# 10.3: Numeric conversions

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Numeric conversions may change range or precision. Converting a finite floating value to an integer discards its fractional part toward zero rather than rounding to the nearest integer.

The source value must fit the destination range. Checking or clamping the source before conversion avoids an out-of-range floating-to-integer conversion.

## Your mission

Implement wholeDegrees(temperature). Clamp a finite double to [-100,100], then return its integer part truncated toward zero. Tested values are finite and between -10000 and 10000. Clamp before converting so the target integer conversion is always in range.

## Expected behavior

- `wholeDegrees(9.9) -> 9`
- `wholeDegrees(-9.9) -> -9`
- `wholeDegrees(120.5) -> 100`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.3`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Numeric conversions](https://www.learncpp.com/cpp-tutorial/numeric-conversions/)
