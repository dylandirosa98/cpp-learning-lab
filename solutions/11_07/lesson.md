# 11.7: Function template instantiation

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

A template definition is a recipe; a call or explicit request causes the needed specialization to be instantiated. Type arguments may be deduced from arguments or supplied explicitly.

A template that compiles for one type can fail or narrow for another. Test several instantiations, especially a wide integer and a floating-point value.

## Your mission

Implement squared<T>(value) by returning value*value as T. Support explicit and deduced instantiations for int, long long, and double. Tested values and products fit their types. Do not store the result in a fixed int intermediate.

## Expected behavior

- `squared(5) -> 25`
- `squared<double>(1.5) -> 2.25`
- `squared<long long>(100000) -> 10000000000`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.7`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Function template instantiation](https://www.learncpp.com/cpp-tutorial/function-template-instantiation/)
