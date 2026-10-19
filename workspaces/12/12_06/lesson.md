# 12.6: Pass by const lvalue reference

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Pass by const reference avoids copying a potentially expensive object while preventing mutation through that parameter. The caller still owns the object and must keep it alive during the call.

Choose a value for cheap scalar inputs and a const reference when borrowing larger owned objects. The interface should express whether the function borrows, copies, or mutates.

## Your mission

Implement longerThan(text,limit), true only when the string length is strictly greater than limit. The string is passed by const reference; do not copy or mutate it. Empty strings and limit zero are valid.

## Expected behavior

- `longerThan("cat",2) -> true`
- `longerThan("cat",3) -> false`
- `longerThan("",0) -> false`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.6`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Pass by const lvalue reference](https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/)
