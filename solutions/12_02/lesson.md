# 12.2: Value categories (lvalues and rvalues)

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

An expression has both a type and a value category. An lvalue identifies an object with identity; a typical rvalue is a temporary value such as a literal or arithmetic result.

A value parameter can be initialized from either kind of argument. Once inside the function, its name denotes a local object, so you can modify that object without modifying the caller.

## Your mission

Implement nextTicket(current), returning the next integer ticket after current without changing the caller. Inputs are between -1000000 and 1000000. Practice incrementing the named local parameter, and compare calls using a named variable, a literal, and an expression. Each caller supplies a value; the parameter itself is a named lvalue inside the function.

## Expected behavior

- `nextTicket(4) -> 5`
- `nextTicket(2+3) -> 6`
- `calling nextTicket(ticket) leaves ticket unchanged`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.2`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Value categories (lvalues and rvalues)](https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/)
