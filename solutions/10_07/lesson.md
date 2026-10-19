# 10.7: Typedefs and type aliases

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A type alias gives an existing type another name; it does not create a distinct type. A domain name such as Cents can clarify what a number represents without changing arithmetic rules.

Units and rounding remain part of your contract. Keep money in integer minor units when that is the required representation, and specify what happens to fractional minor units.

## Your mission

The Cents alias names long long. Implement discountedPrice(price, percent): return price times (100-percent) / 100 in integer cents, discarding any fractional cent. Return -1 for negative price or percent outside [0,100]. Prices are at most 1000000, so multiplication fits Cents.

## Expected behavior

- `discountedPrice(999,10) -> 899`
- `discountedPrice(500,100) -> 0`
- `discountedPrice(-1,10) -> -1`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.7`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Typedefs and type aliases](https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/)
