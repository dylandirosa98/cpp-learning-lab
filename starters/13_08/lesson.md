# 13.8: Struct aggregate initialization

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Aggregate initialization supplies member values in declaration order. Braces express a complete value directly and can help avoid uninitialized member state.

Returning a newly constructed aggregate keeps a transformation separate from mutation. Check both coordinates, because swapped initializer order can still compile.

## Your mission

Implement translated(point,dx,dy), returning a new Point with x+dx and y+dy. The caller's point is unchanged. Use aggregate initialization for the returned Point and keep member order in mind. Coordinates and sums fit int.

## Expected behavior

- `translated(Point{2,3},4,-1) -> Point{6,2}`
- `zero offsets preserve coordinates`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.8`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Struct aggregate initialization](https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/)
