# 13.9: Default member initialization

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Default member initializers specify fallback values in the type definition. Aggregate initialization uses those defaults for members not explicitly initialized.

Create a default-configured object and override only the requested field. This avoids coupling a small override to every default in the type.

## Your mission

Implement configured(retries). Return a Connection using its default timeout=30 and secure=true. If retries >= 0 override only retries; for negative retries keep its default of 3. The struct's defaults are already declared and should be used rather than replacing unrelated fields with zero.

## Expected behavior

- `configured(5) -> timeout 30, retries 5, secure true`
- `configured(-1) -> timeout 30, retries 3, secure true`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.9`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Default member initialization](https://www.learncpp.com/cpp-tutorial/default-member-initialization/)
