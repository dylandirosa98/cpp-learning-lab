# 12.10: Pass by address

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Pass by address passes a pointer value into a function. The function receives a copy of the address but can still modify the caller-owned object by indirection.

A nullable parameter can communicate optional participation. Document whether null is accepted and what it means instead of relying on accidental behavior.

## Your mission

Implement resetIfPresent(value). A non-null pointer means reset that caller-owned integer to zero. A null pointer means no action. Do not allocate, delete, or retain the address.

## Expected behavior

- `n=9; resetIfPresent(&n); -> n=0`
- `resetIfPresent(nullptr) is a safe no-op`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.10`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Pass by address](https://www.learncpp.com/cpp-tutorial/pass-by-address/)
