# 12.9: Pointers and const

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A pointer to const restricts changing the pointee through that pointer; a const pointer instead restricts changing the stored address. These are independent qualifications.

Use read-only pointer parameters for source data and writable pointer parameters for destination data. Validate every optional address before mutation.

## Your mission

Implement copyIfPresent(source,destination). If either pointer is null, return false without changing any object. Otherwise copy the source integer into the destination and return true. source is a pointer to const: do not mutate it. Passing the same object as source and destination is valid.

## Expected behavior

- `source=4,destination=9 -> destination=4, true`
- `null source -> false, destination unchanged`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.9`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Pointers and const](https://www.learncpp.com/cpp-tutorial/pointers-and-const/)
