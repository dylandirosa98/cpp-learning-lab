# 10.5: Arithmetic conversions

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Mixed arithmetic and comparisons use common-type rules. Mixing signed and unsigned values can convert a negative signed operand into a large unsigned value.

Validate the signed domain before converting it to unsigned. An explicit cast after the guard makes the intended comparison clear.

## Your mission

Implement fitsInBudget(cost, budget). Negative signed costs are invalid and return false. Otherwise return whether cost is at most the unsigned budget, including equality. Tested costs fit int and budgets may include the maximum unsigned int value.

## Expected behavior

- `fitsInBudget(-1,100u) -> false`
- `fitsInBudget(100,100u) -> true`
- `fitsInBudget(101,100u) -> false`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 10.5`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Arithmetic conversions](https://www.learncpp.com/cpp-tutorial/arithmetic-conversions/)
