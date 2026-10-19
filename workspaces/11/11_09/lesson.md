# 11.9: Non-type template parameters

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A non-type template parameter supplies a compile-time value rather than a type. Different values identify different specializations of the template.

Separate configuration known at compilation from data supplied at runtime. Here the factor is compile-time configuration, while each call can scale a different runtime value.

## Your mission

Implement scaleBy<Factor>(value), multiplying an int value by the compile-time integer Factor. Factor may be positive, zero, or negative. All products fit int. Factor is a template argument, not a runtime function parameter.

## Expected behavior

- `scaleBy<3>(7) -> 21`
- `scaleBy<0>(7) -> 0`
- `scaleBy<-2>(7) -> -14`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.9`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Non-type template parameters](https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/)
