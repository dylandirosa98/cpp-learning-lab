# 10.2: Floating-point and integral promotion

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Small integral types generally promote to int before arithmetic. Promotion is a particular value-preserving conversion, not a general promise that every conversion is safe.

Keep intermediate and result storage wide enough. Assigning the promoted sum back into a small type can lose the range that promotion gave you.

## Your mission

Implement addSmall(signed char left, short right), returning their sum as int. Inputs use left in [-100,100] and right in [-30000,30000]. Do not store the result in either small input type. Integral promotion lets the arithmetic use int without losing the sum.

## Expected behavior

- `addSmall(100,30000) -> 30100`
- `addSmall(-100,-30000) -> -30100`
- `addSmall(-10,20) -> 10`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.2`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Floating-point and integral promotion](https://www.learncpp.com/cpp-tutorial/floating-point-and-integral-promotion/)
