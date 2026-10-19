# 9.5: std::cin and handling invalid input

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

**Route:** Learn → predict → code → run tests → explain → submit.

This experimental chapter uses a guided, challenge-first lesson format. Everything needed for the mission is in this folder; external reading is optional enrichment.

## Learn: understand stream state

Extraction with >> attempts to parse a value and reports success through the stream. Invalid syntax or an out-of-range integer sets failure state. Further reads will not recover merely by trying again. On a recoverable failure, clear the state and discard the invalid line before retrying. Do not use the value from a failed extraction.

## Line policy and leftover characters

This exercise accepts an integer at the beginning of a line and discards the remainder. Thus "3 extra" is intentionally accepted as 3, while a line beginning with "extra" is rejected. Different programs may require strict whole-line parsing, but mixing those two policies silently makes tests confusing. ignore(max, newline) consumes through the newline or end of the source.

## EOF is a different kind of failure

If input is exhausted, clearing state and retrying forever cannot create more input. Return the EOF sentinel instead. Conversely, a final valid integer can be extracted successfully even without a trailing newline; handle extraction success before rejecting EOF. Blank leading whitespace may be skipped by formatted extraction.

## How the visible tests supply input

The supplied test scaffold temporarily routes std::cin to an in-memory string stream, calls your reader, and restores it. You only implement the reader; do not request keyboard input in main or replace the test scaffold. Later chapters explain the reference and pointer syntax used by this scaffold. Alt+R should finish without waiting for typing.

## Reflect

Why must clear() happen before ignore() after a parse failure? Why is EOF handled before attempting another retry? Which test ensures a successful final integer is not lost?

## Your mission

Implement readQuantity() using std::cin. Read an integer at the beginning of each attempted line; discard the rest of that line. Return the first integer in [1,20]. On invalid text, an out-of-range number, or integer overflow, discard that line and retry. On end-of-input before a valid value, return -1. A line beginning "3 extra" is accepted as 3; this is intentionally not a strict whole-line parser. Do not print prompts. Test scaffolding supplies simulated input automatically.

## Expected behavior

- `input "hello\n0\n8\n" -> 8`
- `input "21\n1\n" -> 1`
- `empty input -> -1`
- `input "20" with no final newline -> 20`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 9.5`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: std::cin and handling invalid input](https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/)
