# 12.3: Lvalue references

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

An lvalue reference is an alias bound to an existing object. Reading or assigning through it accesses that object rather than an independent reference-owned value.

A non-const lvalue reference must bind to an appropriate modifiable lvalue. It cannot be reseated to a different object after initialization.

## Your mission

Implement addTo(target,delta). target is an int lvalue reference: change the caller's integer by adding delta. delta may be negative or zero. Inputs and sums fit int. A reference is an alias to the existing object, not a separate copy to return.

## Expected behavior

- `int n=4; addTo(n,3); -> n is 7`
- `addTo(n,-2) subtracts two`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.3`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Lvalue references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
