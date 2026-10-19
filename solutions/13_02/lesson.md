# 13.2: Unscoped enumerations

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

An enumeration names a closed set of domain choices. Unscoped enumerator names enter the surrounding scope, so their names must avoid collisions there.

Use meaningful enumerators to make branching readable. The behavior of a direction operation should not depend on callers remembering numeric positions.

## Your mission

Implement turnRight(direction) for the supplied unscoped Direction enum. Rotate north -> east -> south -> west -> north. Inputs are always one of those four enumerators. Prefer a switch with named cases rather than relying on undocumented integer codes.

## Expected behavior

- `turnRight(north) -> east`
- `turnRight(west) -> north`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.2`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Unscoped enumerations](https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/)
