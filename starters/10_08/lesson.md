# 10.8: Type deduction for objects using the auto keyword

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

auto deduces an object type from its initializer. The expression still has its ordinary type: auto does not turn integer division into floating-point division.

Use a clear initializer so the deduced type is intentional. const auto can keep the deduced value immutable without repeating its exact type.

## Your mission

Implement midpoint(low, high) returning their floating-point midpoint, even for odd sums or reversed endpoints. Inputs are between -1000000 and 1000000. Use auto for a local intermediate so its type follows the expression; the tests care about the double result, not how you spell locals.

## Expected behavior

- `midpoint(1,4) -> 2.5`
- `midpoint(4,1) -> 2.5`
- `midpoint(-4,1) -> -1.5`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.8`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Type deduction for objects using the auto keyword](https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/)
