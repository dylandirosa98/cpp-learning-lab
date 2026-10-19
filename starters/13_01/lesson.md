# 13.1: Introduction to program-defined (user-defined) types

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A program-defined type gives a domain concept its own identity rather than only another name for a built-in type. Structs and enumerations are two important ways to define such types.

A small value type can make units explicit in an API. Passing and returning Money communicates cents without relying solely on parameter names.

## Your mission

The supplied Money struct represents integer cents. Implement addMoney(left,right), returning a new Money containing the sum. Negative amounts are allowed. Do not mutate either input. Tested sums fit int. Return the program-defined type, not a plain int.

## Expected behavior

- `addMoney(Money{125},Money{75}).cents -> 200`
- `adding -50 cents subtracts 50 cents`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.1`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Introduction to program-defined (user-defined) types](https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/)
