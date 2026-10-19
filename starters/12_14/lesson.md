# 12.14: Type deduction with pointers, references, and const

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Plain auto often drops reference and top-level const qualifications when deducing a new object. auto& explicitly asks to retain reference behavior.

Type deduction syntax is part of the API when callers depend on aliasing. Verify both the deduced type and that writes reach the intended original object.

## Your mission

Implement selectCounter(first,second,chooseFirst), preserving a modifiable lvalue reference in its deduced return type. chooseFirst selects first when true, otherwise second. The signature uses auto&; returning a value copy would break assignment through the result.

## Expected behavior

- `selectCounter(a,b,true)=7; -> a=7`
- `selectCounter(a,b,false)=9; -> b=9`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.14`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Type deduction with pointers, references, and const](https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/)
