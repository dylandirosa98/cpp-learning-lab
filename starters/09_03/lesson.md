# 9.3: Common semantic errors in C++

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

**Route:** Learn → predict → code → run tests → explain → submit.

This experimental chapter uses a guided, challenge-first lesson format. Everything needed for the mission is in this folder; external reading is optional enrichment.

## Learn: valid syntax can encode the wrong algorithm

A semantic error means the program does not mean what you intended. Common examples include integer division where a fraction is needed, assignment instead of equality, incorrect Boolean grouping, off-by-one loop endpoints, unintended empty statements, and state updates in the wrong order. Warnings catch some of these, not all.

## Worked example: conversion timing

Five integer points divided among two entries must average 2.5. Integer division produces 2 before any later conversion to double. Making the final destination a double does not retroactively reevaluate that division. Trace the operand types as well as their values.

## A focused debugging loop

Pick the smallest failing input, record expected and actual results, and trace each condition and intermediate expression. Test one hypothesis at a time. After fixing the fraction, check count zero, negative count, negative total, and zero total so a repair does not create a new edge-case error. Enable compiler warnings and treat them as evidence even though this challenge grades behavior.

## Reflect

Why is zero total valid while zero count is not? What changes if you convert an operand before division instead of converting the quotient afterward?

## Your mission

Implement averageScore(total, count), returning a floating-point average. Return -1.0 if total < 0 or count <= 0. Inputs are at most 10000. In particular, 5 / 2 must produce 2.5 rather than 2.0. This challenge targets integer division, incorrect guards, and forgotten return paths.

## Expected behavior

- `averageScore(5,2) -> 2.5`
- `averageScore(0,3) -> 0.0`
- `averageScore(5,0) -> -1.0`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 9.3`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Common semantic errors in C++](https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/)
