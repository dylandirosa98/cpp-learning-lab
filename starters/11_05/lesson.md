# 11.5: Default arguments

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Default arguments supply omitted trailing call arguments; they do not create extra overloads. Once a parameter has a default, later parameters in that declaration must also have defaults.

Defaults belong where callers can see them and should not be repeated across declarations and definitions. Callers can override earlier defaults only by supplying the needed preceding arguments.

## Your mission

Implement shippingCost(distance, packages, rate). Return distance*packages*rate, or -1 if distance < 0, packages < 1, or rate < 0. Add defaults so packages is 1 and rate is 2 when omitted. The stub deliberately has no defaults yet: adding the defaults is part of the exercise. All tested products fit int.

## Expected behavior

- `shippingCost(5) -> 10`
- `shippingCost(5,3) -> 30`
- `shippingCost(5,3,4) -> 60`
- `shippingCost(5,0) -> -1`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.5`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Default arguments](https://www.learncpp.com/cpp-tutorial/default-arguments/)
