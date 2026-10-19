# 12.1: Introduction to compound data types

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Compound types build on or relate to other types; examples include functions, references, pointers, arrays, and class types such as std::string. A compound type has its own rules for copying and lifetime.

A value parameter is a local object initialized from its argument. Modifying an owned string value changes that local copy, not the caller.

## Your mission

Implement appendTag(name,tag), returning an owned std::string containing name + "[" + tag + "]". name is passed by value, so editing the local copy must not change the caller. Empty names and tags are valid. This builds on the string class type you already know while introducing the idea of compound types.

## Expected behavior

- `appendTag("Ada","cpp") -> "Ada[cpp]"`
- `appendTag("","") -> "[]"`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 12.1`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Introduction to compound data types](https://www.learncpp.com/cpp-tutorial/introduction-to-compound-data-types/)
