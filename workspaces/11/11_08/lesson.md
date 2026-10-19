# 11.8: Function templates with multiple template types

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Independent template parameters permit heterogeneous arguments. A single T parameter for both arguments normally requires compatible deduction of one T, not arbitrary mixed arguments.

Multiple type parameters do not disable arithmetic conversions. Convert at the intended stage when the domain calls for floating-point mathematical addition.

## Your mission

Implement sumAsDouble<T,U>(left,right), returning the mathematical sum as double. Convert each operand to double BEFORE adding so mixed signed/unsigned inputs do not wrap. Tested values are small integers or finite doubles and are exactly representable or checked within 1e-9.

## Expected behavior

- `sumAsDouble(-3,2u) -> -1.0`
- `sumAsDouble(2,0.5) -> 2.5`
- `sumAsDouble(1.25,2) -> 3.25`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.8`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Function templates with multiple template types](https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/)
