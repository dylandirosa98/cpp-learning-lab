# 12.5: Pass by lvalue reference

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Pass by non-const lvalue reference lets a function intentionally change caller-owned objects. The signature communicates that mutation is possible.

Two references can alias the same object. Prefer a simple temporary during swapping rather than relying on arithmetic tricks that break under aliasing or overflow.

## Your mission

Implement sortPair(first,second), modifying the caller so first <= second. Swap only when necessary. If both reference parameters refer to the same integer, leave that integer unchanged. Values fit int; do not use arithmetic swapping that could overflow.

## Expected behavior

- `a=8,b=3; sortPair(a,b); -> a=3,b=8`
- `sortPair(a,a) leaves a unchanged`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.5`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Pass by lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/)
