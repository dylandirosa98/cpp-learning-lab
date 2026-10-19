# 12.12: Return by reference and return by address

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Returning a reference exposes an existing object instead of making a value copy. The referenced object must remain alive for every subsequent use by the caller.

Returning a reference to a local variable creates a dangling reference. Borrowing one of the caller's lvalue arguments is safe here because the caller retains those objects.

## Your mission

Implement largerRef(first,second), returning an int reference to the larger caller-owned integer. On a tie return first. Do not return a local copy or a temporary. The caller may assign through the returned reference; tests check object identity, not just equal values.

## Expected behavior

- `a=3,b=8; largerRef(a,b)=20; -> b=20`
- `equal values -> reference to first`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.12`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Return by reference and return by address](https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/)
