# 9.1: Introduction to testing your code

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

**Route:** Learn → predict → code → run tests → explain → submit.

This experimental chapter uses a guided, challenge-first lesson format. Everything needed for the mission is in this folder; external reading is optional enrichment.

## Learn: turn a requirement into an experiment

A useful test has three parts: arrange an input, act by calling the function, and assert an expected result. Choose the expectation from the written requirement, not by running your current implementation and copying whatever it returns. Otherwise a bug can become the expected answer.

For this mission, ordinary years, years divisible by four, century years, and years divisible by four hundred are different input categories. Invalid years add another category. A single passing example only tells you about that example.

## Worked example: why 1900 matters

1900 is divisible by four, but the century exception rejects it. 2000 is also a century, but the four-hundred-year exception accepts it. Those two tests distinguish several plausible but incorrect implementations. The examples explain the decision, not the implementation syntax.

## Testing practice

Run the unfinished program first: a failing test proves the test harness can detect missing behavior. Implement a small change, rerun, then run the entire suite after each fix. Keep deterministic tests fast so using them becomes a habit. Add your own test without deleting the supplied ones. Manual exploration is useful too, but repeatable assertions keep earlier discoveries from being forgotten.

## Reflect

Which test rejects a plain divisible-by-four implementation? Which rejects a rule that excludes every century? Explain why successful compilation cannot answer either question.

## Your mission

Implement isLeapYear(year). A positive year is a leap year when divisible by 400, or divisible by 4 but not by 100. Nonpositive years return false. Before implementing it, predict each visible test and add one example of your own. The test suite is executable documentation, not text you must print.

## Expected behavior

- `isLeapYear(2024) -> true`
- `isLeapYear(1900) -> false`
- `isLeapYear(2000) -> true`
- `isLeapYear(0) -> false`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 9.1`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Introduction to testing your code](https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/)
