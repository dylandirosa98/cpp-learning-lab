# 13.14: Class template argument deduction (CTAD) and deduction guides

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

CTAD uses initialization arguments to deduce class template arguments. A deduction guide specifies how argument types map to a specialization; it is not a function body.

Deducing a common type for mixed numeric arguments prevents accidental truncation. The resulting object must really store that type, not merely cast during a later calculation.

## Your mission

Add a deduction guide so Pair{left,right} deduces Pair<std::common_type_t<T,U>> from possibly mixed numeric arguments. Then implement spanOf(pair), returning the absolute difference of its two members as T. Pair{2,5.5} must store two doubles, not truncate. std::common_type_t is provided by <type_traits>; it names the common arithmetic type. Inputs and differences fit their types.

## Expected behavior

- `Pair{2,5.5} has type Pair<double>`
- `spanOf(Pair{2,5.5}) -> 3.5`
- `spanOf(Pair{8,3}) -> 5`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.14`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Class template argument deduction (CTAD) and deduction guides](https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/)
