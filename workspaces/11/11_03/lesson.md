# 11.3: Function overload resolution and ambiguous matches

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Overload resolution prefers better matches, such as exact matches and then promotions over ordinary numeric conversions. If no unique best viable overload exists, compilation fails with ambiguity.

Inspect argument types rather than just their displayed numeric values. A float literal and an integer literal can select different operations even when both look like four.

## Your mission

Implement scale(int) to return twice the input as double, and scale(double) to return 1.5 times the input. The visible tests also call scale with a char and a float: reason about which overload is selected by promotion. All values are small and finite.

## Expected behavior

- `scale(4) -> 8.0`
- `scale(4.0) -> 6.0`
- `scale(char{4}) -> 8.0`
- `scale(4.0f) -> 6.0`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.3`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Function overload resolution and ambiguous matches](https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/)
