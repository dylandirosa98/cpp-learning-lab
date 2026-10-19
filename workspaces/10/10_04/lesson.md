# 10.4: Narrowing conversions, list initialization, and constexpr initializers

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Brace initialization rejects many narrowing conversions because they can lose information. Some constant-expression conversions are allowed when the compiler can prove the exact value is representable.

An explicit cast acknowledges a conversion but does not make an invalid value valid. Validate runtime values first, then convert the known-safe result.

## Your mission

Implement clampChannel(value), returning an unsigned char in [0,255]. Negative inputs become 0, inputs above 255 become 255, and in-range values are preserved. Do not allow wraparound. This challenge uses runtime range validation followed by an explicit narrowing conversion.

## Expected behavior

- `clampChannel(-1) -> 0`
- `clampChannel(256) -> 255`
- `clampChannel(128) -> 128`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.4`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Narrowing conversions, list initialization, and constexpr initializers](https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/)
