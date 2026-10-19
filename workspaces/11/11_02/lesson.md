# 11.2: Function overload differentiation

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Overloads can differ by parameter number or parameter types. Renaming a parameter, changing only its default, or changing only the return type does not create a distinct overload.

The same operation can serve different domains while retaining domain-appropriate comparisons. For strings, compare text values rather than raw storage addresses.

## Your mission

Implement sameValue(int,int) and sameValue(std::string_view,std::string_view). Return exact equality for each pair. Text comparison is case-sensitive and compares contents, not addresses. Empty text equals empty text. Parameter names and return types are not what distinguish these overloads.

## Expected behavior

- `sameValue(2,2) -> true`
- `sameValue("cat","Cat") -> false`
- `sameValue("","") -> true`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 11.2`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Function overload differentiation](https://www.learncpp.com/cpp-tutorial/function-overload-differentiation/)
