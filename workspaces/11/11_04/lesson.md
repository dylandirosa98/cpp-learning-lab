# 11.4: Deleting functions

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A deleted function participates in overload resolution but cannot be called. Deleting a better-matching overload prevents a call from silently converting to another overload.

This is an interface property, not a text-matching exercise. The tests ask the compiler whether a particular call is well formed instead of searching for a particular source line.

## Your mission

Implement wholeUnits(int units): return units when nonnegative, otherwise 0. Also prohibit calls with a double by declaring the double overload deleted. Add that declaration in the indicated API area, not an implementation that truncates. The visible compile-time tests verify that int calls are valid and double calls are not.

## Expected behavior

- `wholeUnits(7) -> 7`
- `wholeUnits(-1) -> 0`
- `wholeUnits(2.5) must not be a valid call`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.4`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Deleting functions](https://www.learncpp.com/cpp-tutorial/deleting-functions/)
