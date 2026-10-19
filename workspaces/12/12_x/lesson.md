# 12.x: Chapter 12 summary and quiz

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

An optional result can describe a mutation that may fail, while pointers identify optional caller-owned objects. Treat validation as a transaction boundary: do not change state until every precondition passes.

Aliasing matters when multiple parameters identify writable objects. Explicitly rejecting identical accounts makes the contract predictable and keeps validation independent of mutation order.

## Your mission

Implement transfer(from,to,amount), returning optional<int> with the new source balance on success. Both pointers must be non-null and distinct, both balances nonnegative, amount nonnegative, and source must have enough funds. On any invalid condition return nullopt and change neither balance. A zero transfer succeeds. Starting balances and amount are at most 10000, so sums fit int. Do not allocate or own the pointed-to accounts.

## Expected behavior

- `from=10,to=3,amount=4 -> from=6,to=7,result=6`
- `amount greater than balance -> nullopt, unchanged`
- `same account pointer -> nullopt`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.x`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Chapter 12 summary and quiz](https://www.learncpp.com/cpp-tutorial/chapter-12-summary-and-quiz/)
