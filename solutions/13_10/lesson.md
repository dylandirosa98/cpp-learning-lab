# 13.10: Passing and returning structs

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Functions can borrow structs through const references and return newly computed structs by value. This keeps related results together rather than spreading them across unrelated outputs.

Read-only inputs and new result values make composition straightforward. Avoid integer division when turning integer counters into a fractional summary.

## Your mission

Implement combine(left,right), returning Stats with summed wins and losses without changing inputs, and winRate(stats), returning wins/(wins+losses) as double. Empty stats have rate 0.0. Supplied counts are nonnegative and their sums fit int. Rate is a fraction, not a percentage.

## Expected behavior

- `combine(Stats{2,1},Stats{1,3}) -> Stats{3,4}`
- `winRate(Stats{1,3}) -> 0.25`
- `winRate(Stats{}) -> 0.0`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.10`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Passing and returning structs](https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/)
