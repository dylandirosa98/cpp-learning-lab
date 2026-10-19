# 11.10: Using function templates in multiple files

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Call sites normally need to see a template definition to instantiate it. A declaration alone in a header with the generic definition hidden in an unrelated source file is not enough.

Header guards prevent repeated inclusion in one translation unit; template definitions in headers can then be used consistently by multiple translation units.

## Your mission

Implement minOf<T>(left,right) in numeric.h, returning the smaller value (first on equality). Keep the full template definition visible in the header. main.cpp and the supplied probe.cpp both instantiate it; Alt+R through the provided CMake target builds both files. Do not edit the probe or put an int-only replacement in main.cpp.

## Expected behavior

- `minOf(3,8) -> 3`
- `minOf(1.5,1.25) -> 1.25`
- `minimumFromOtherFile(8,3) -> 3`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.10`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Using function templates in multiple files](https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/)
