# 12.4: Lvalue references to const

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A reference to const allows read-only access through that reference and can bind to const lvalues and many temporary values. It does not necessarily make the original object globally immutable.

Returning by value here avoids exposing a reference tied to an argument that may be a temporary. Read-only access and return lifetime are separate design choices.

## Your mission

Implement maxReadOnly(left,right), returning the larger int by value. The parameters are references to const, so the function must not alter either argument and must also accept const objects and temporary integers.

## Expected behavior

- `maxReadOnly(3,8) -> 8`
- `maxReadOnly(-2,-4) -> -2`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.4`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Lvalue references to const](https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/)
