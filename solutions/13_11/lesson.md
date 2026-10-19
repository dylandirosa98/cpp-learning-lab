# 13.11: Struct miscellany

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Structs can contain other struct objects, creating a hierarchy of related data. Chained member selection follows those nested objects.

Avoid assuming an object's memory size equals the sum of member sizes: implementations may add padding. Access members by name rather than by raw offsets.

## Your mission

Implement movePlayer(player,dx,dy), changing only the nested position coordinates of the caller's Player. Preserve name and health exactly. Position is a nested program-defined member type, not an independent global position variable. Sums fit int.

## Expected behavior

- `Player{"Ada",{2,3},90} moved by (4,-1) -> position {6,2}, name/health unchanged`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.11`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Struct miscellany](https://www.learncpp.com/cpp-tutorial/struct-miscellany/)
