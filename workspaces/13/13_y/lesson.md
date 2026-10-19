# 13.y: Using a language reference

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A language reference is organized for precise lookup: headers, signatures, version availability, preconditions, return values, and invalidation or lifetime notes matter more than a quick example alone.

std::clamp assumes ordered bounds and returns a reference to one of its arguments. This wrapper normalizes the bounds and returns an int by value, so no reference to a local parameter escapes.

## Your mission

Use the standard-library reference linked in lesson.md to implement boundedTemperature(reading,low,high). If low > high, swap the bounds first. Then return reading clamped to the inclusive interval. Practice finding std::clamp requirements, return type, and header rather than copying an unrelated example. All values are ints.

## Expected behavior

- `boundedTemperature(20,0,10) -> 10`
- `boundedTemperature(-3,10,0) -> 0`
- `boundedTemperature(5,0,10) -> 5`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.y`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Reference-reading task

Read [std::clamp](https://en.cppreference.com/w/cpp/algorithm/clamp.html). Locate its header, ordered-bounds precondition, version availability, and reference return type. Explain why this wrapper normalizes bounds and returns by value.

## Continue reading

[LearnCpp: Using a language reference](https://www.learncpp.com/cpp-tutorial/using-a-language-reference/)
