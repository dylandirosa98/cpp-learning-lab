# 11.1: Introduction to function overloading

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

An overload set contains functions sharing a name but accepting different parameter types. A call selects an overload from its argument types, letting one operation have appropriately typed implementations.

Return type alone cannot distinguish two overloads with identical parameter lists. The caller must be able to choose before using the return value.

## Your mission

Implement both doubleValue overloads: int -> int and double -> double. Each returns twice its argument, preserving the appropriate result type. Integer inputs are at most one million in magnitude. Do not convert the double overload through int.

## Expected behavior

- `doubleValue(3) -> 6`
- `doubleValue(1.25) -> 2.5`
- `doubleValue(-2) -> -4`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.1`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Introduction to function overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/)
