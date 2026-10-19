# 11.x: Chapter 11 summary and quiz

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A generic API can combine deduced type parameters with explicit compile-time policy values. Keep the mathematical contract independent of the syntax used at the call site.

Exercise several specializations and boundary policies rather than a single happy-path instance. This catches accidentally fixed result types and hard-coded template values.

## Your mission

Implement clampValue<T>(value, low, high) and discounted<Percent,T>(price). clampValue returns low below the lower bound, high above the upper bound, or value inside; low <= high is guaranteed. discounted returns price*(100-Percent)/100.0 as double, preserving fractions. Percent is a compile-time integer in [0,100]; prices are finite and nonnegative. Both templates must work with int and double inputs.

## Expected behavior

- `clampValue(12,0,10) -> 10`
- `clampValue(0.25,0.0,1.0) -> 0.25`
- `discounted<25>(10) -> 7.5`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.x`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Chapter 11 summary and quiz](https://www.learncpp.com/cpp-tutorial/chapter-11-summary-and-quiz/)
