# 12.7: Introduction to pointers

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A pointer stores an address. The address-of operator obtains an object's address, while indirection accesses the object at a valid pointed-to address.

Changing a value through a pointer differs from changing which address the local pointer stores. Pointers do not own an object merely because they point to it.

## Your mission

Implement doublePointed(value), doubling the caller's integer through a pointer. For this lesson the pointer is guaranteed non-null and the product fits int. Use indirection to access the pointed-to object rather than modifying the local pointer value.

## Expected behavior

- `n=4; doublePointed(&n); -> n=8`
- `n=-3 -> n=-6`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.7`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Introduction to pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/)
