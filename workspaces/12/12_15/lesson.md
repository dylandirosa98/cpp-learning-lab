# 12.15: std::optional

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

std::optional<T> represents either a T value or no value. It avoids sentinel ambiguity, especially when every ordinary T value could be a valid result.

Check engagement before dereferencing or use value_or when a fallback is appropriate. An engaged optional containing zero is still engaged.

## Your mission

Implement parseDigit(character). For ASCII characters 0..9 return an engaged std::optional<int> containing the numeric digit. For any other character return std::nullopt. An engaged zero is a valid result and is different from an empty optional.

## Expected behavior

- `parseDigit('0') -> optional containing 0`
- `parseDigit('9') -> optional containing 9`
- `parseDigit('x') -> nullopt`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.15`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: std::optional](https://www.learncpp.com/cpp-tutorial/stdoptional/)
