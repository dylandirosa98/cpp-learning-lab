# 13.15: Alias templates

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

An alias template maps template arguments to an existing type expression. Instantiating the alias does not create a distinct type or new data storage.

Forward the intended type arguments instead of accidentally fixing them. A type-identity test can catch an alias that looks generic but always selects one concrete type.

## Your mission

Fix the ScorePair<T> alias so it preserves T instead of always selecting Pair<int>. Then implement maxScore<T>(pair), returning the larger stored value as T (first on equality). The alias names an existing specialization; it does not define a new struct. Both integer and double scores are tested.

## Expected behavior

- `ScorePair<double> must be the same type as Pair<double>`
- `maxScore<double>({1.25,2.5}) -> 2.5`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.15`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Alias templates](https://www.learncpp.com/cpp-tutorial/alias-templates/)
