# 10.6: Explicit type conversion (casting) and static_cast

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

static_cast requests an explicit conversion between compatible types. It makes an intentional numeric change visible but does not perform range validation for you.

Apply the cast before the operation that needs the wider type. A cast around an integer-division expression happens too late to preserve its fraction.

## Your mission

Implement successRate(successes, attempts) as a percentage in [0,100]. Return -1.0 when attempts <= 0, successes < 0, or successes > attempts. Preserve fractional percentages. Counts are at most 100000.

## Expected behavior

- `successRate(1,4) -> 25.0`
- `successRate(1,8) -> 12.5`
- `successRate(0,0) -> -1.0`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.6`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Explicit type conversion (casting) and static_cast](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)
