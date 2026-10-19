# 9.6: Assert and static_assert

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

**Route:** Learn → predict → code → run tests → explain → submit.

This experimental chapter uses a guided, challenge-first lesson format. Everything needed for the mission is in this folder; external reading is optional enrichment.

## Learn: programmer assumptions versus user mistakes

An assertion documents a condition the programmer believes must already hold. User input can legitimately be bad, so validate it with ordinary control flow and a useful recovery path. If a programmer passes an impossible percentage to a debug-only internal helper, assert can expose that mistake immediately.

## Runtime assertions

Include <cassert> and use assert(condition). A false condition terminates the process in an assertion-enabled build. When NDEBUG is defined, the assertion can disappear entirely. Never put required work such as incrementing a counter inside assert, and never rely on assert alone for external input validation.

## Compile-time assertions

static_assert requires a constant expression and is checked during compilation. The validPercent function is constexpr so both the compiler and runtime callers can use the same pure predicate. A failed static_assert intentionally prevents compilation; it is not a failed runtime branch.

## Running the challenge

The tests run valid calls normally and invalid calls in isolated child processes, checking specifically for an assertion abort rather than any crash. Core dumps are disabled for those child tests. The supplied CMake target keeps assertions enabled even when another build configuration defines NDEBUG. These subprocess tests support Linux and macOS.

## Reflect

What would change in a release build with NDEBUG? Why would assert(readInput()) be a dangerous place to perform required input work?

## Your mission

Implement constexpr validPercent(percent), true exactly for [0,100], and checkedPercent(percent), which asserts that precondition then returns the input. validPercent must work in constant expressions. checkedPercent must abort on invalid values in a debug build, not return a sentinel. The provided tests isolate invalid calls in child processes so Alt+R still reports results. Run these tests with assertions enabled (no NDEBUG, and a Debug CMake build). Assertions document programmer mistakes; they are not user-input validation.

## Expected behavior

- `validPercent(0) -> true`
- `validPercent(101) -> false`
- `checkedPercent(45) -> 45`
- `checkedPercent(-1) -> assertion abort`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 9.6`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Assert and static_assert](https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/)
