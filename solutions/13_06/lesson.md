# 13.6: Scoped enumerations (enum classes)

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Scoped enumerations keep enumerator names inside the enum scope and do not implicitly convert to integers. This reduces name collisions and accidental mixed-domain comparisons.

Use the domain alternatives directly when expressing policy. Explicit scope qualification documents which kind of access a branch is discussing.

## Your mission

Implement canEdit(access, ownsDocument). Admins can edit every document; members can edit only their own; guests can never edit. Use the scoped Access enumerators rather than treating access as an integer.

## Expected behavior

- `canEdit(Access::admin,false) -> true`
- `canEdit(Access::member,false) -> false`
- `canEdit(Access::member,true) -> true`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.6`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Scoped enumerations (enum classes)](https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/)
