# 12.8: Null pointers

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

nullptr expresses the absence of an address. Testing a pointer checks whether it is null; testing the pointed-to integer checks an entirely different thing.

A non-null check is necessary before indirection but does not prove that an arbitrary pointer is otherwise valid. These tests supply either live objects or nullptr.

## Your mission

Implement valueOr(value,fallback), returning the pointed-to integer when value is non-null, otherwise fallback. Do not dereference a null pointer. The pointee is read-only through this pointer.

## Expected behavior

- `valueOr(nullptr,7) -> 7`
- `n=0; valueOr(&n,7) -> 0`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.8`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Null pointers](https://www.learncpp.com/cpp-tutorial/null-pointers/)
