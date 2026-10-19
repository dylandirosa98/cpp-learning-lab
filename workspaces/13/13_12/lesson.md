# 13.12: Member selection with pointers and references

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

The dot operator selects a member of an object or a reference to an object. The arrow operator selects a member through a pointer and corresponds to dereferencing then using dot.

Member selection through a null pointer is invalid. Establish pointer validity before accessing any of its members.

## Your mission

Implement incrementCounter(counter,delta). Return false for nullptr and do nothing. Otherwise add delta to the pointed-to Counter's value and return true. delta may be negative or zero and results fit int. Practice the -> operator for pointer member selection.

## Expected behavior

- `Counter{4} incremented by 3 -> value 7, true`
- `nullptr -> false`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.12`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Member selection with pointers and references](https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/)
