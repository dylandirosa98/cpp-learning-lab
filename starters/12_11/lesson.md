# 12.11: Pass by address (part 2)

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A pointer passed by value can be locally reseated without changing the caller's pointer. A reference to that pointer permits intentional reseating of the caller's pointer variable.

Address management and pointee mutation are separate operations. This function changes the chosen object without changing the values stored in either object.

## Your mission

Implement redirect(active,replacement). active is a reference to the caller's pointer variable: make that pointer store replacement, including nullptr. Do not modify either pointed-to integer. This differs from changing only a local copy of a pointer.

## Expected behavior

- `active=&a; redirect(active,&b); -> active==&b`
- `redirect(active,nullptr); -> active==nullptr`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.11`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Pass by address (part 2)](https://www.learncpp.com/cpp-tutorial/pass-by-address-part-2/)
