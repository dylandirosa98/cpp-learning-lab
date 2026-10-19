# 13.7: Introduction to structs, members, and member selection

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A struct groups related members into one object. Member selection with the dot operator accesses a named part of that object.

Domain invariants still matter after grouping data. Equal dimensions alone do not make a valid square when the contract excludes zero and negative lengths.

## Your mission

Implement area(rectangle) and isSquare(rectangle). A rectangle with either dimension <= 0 is invalid: its area is 0 and isSquare is false. Otherwise area is width*height and a square has equal dimensions. Dimensions and products fit int.

## Expected behavior

- `Rectangle{3,4} -> area 12, not square`
- `Rectangle{3,3} -> area 9, square`
- `Rectangle{0,0} -> area 0, not square`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.7`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Introduction to structs, members, and member selection](https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/)
