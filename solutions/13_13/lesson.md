# 13.13: Class templates

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A class template describes a family of types, not just a family of functions. Pair<int> and Pair<double> are different types with correspondingly typed members.

Use the template parameter for the stored data, not just for a function's return type. Hard-coding int members would lose fractional values before pairSum could preserve them.

## Your mission

Complete the Pair<T> struct with two value-initialized members, T first{} and T second{}, then implement pairSum(pair), returning their sum as T. The member declarations are intentionally left for you. Support Pair<int> and Pair<double>; template arguments choose the member types as well as the function instance.

## Expected behavior

- `Pair<int>{2,3} has sum 5`
- `Pair<double>{1.25,2.5} has sum 3.75`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.13`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Class templates](https://www.learncpp.com/cpp-tutorial/class-templates/)
