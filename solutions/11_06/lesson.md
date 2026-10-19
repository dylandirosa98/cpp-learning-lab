# 11.6: Function templates

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A function template describes a family of functions parameterized by type. Instantiation creates a concrete function when a particular type is needed.

Use operations supported by every tested type. A generic maximum needs comparison and copying but should not force a numeric-only conversion.

## Your mission

Implement maxOf<T>(left,right), returning the larger value, or the first value when equal. The provided template parameter T lets the same body work for int, double, and std::string. Return T, not int, so text and fractional values survive.

## Expected behavior

- `maxOf(3,8) -> 8`
- `maxOf(1.5,1.25) -> 1.5`
- `maxOf(string("ant"),string("bee")) -> "bee"`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.6`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Function templates](https://www.learncpp.com/cpp-tutorial/function-templates/)
