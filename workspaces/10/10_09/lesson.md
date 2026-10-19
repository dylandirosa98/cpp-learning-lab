# 10.9: Type deduction for functions

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

An auto return type is deduced from the function definition. Ordinary return statements in the same deduced-return function must agree on the deduced type.

Return-type deduction does not replace thinking about the API. Decide the type callers should receive, then ensure all paths produce it.

## Your mission

Implement auto absoluteGap(left, right), returning the nonnegative integer distance between two integers. Every return path must deduce the same type, int. Inputs lie between -1000000 and 1000000. Keep the definition before callers so its return type can be deduced.

## Expected behavior

- `absoluteGap(3,8) -> 5`
- `absoluteGap(8,3) -> 5`
- `absoluteGap(-4,2) -> 6`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.9`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Type deduction for functions](https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/)
