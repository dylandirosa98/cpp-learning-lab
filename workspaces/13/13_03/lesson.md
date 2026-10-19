# 13.3: Unscoped enumerator integral conversions

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Unscoped enumerations can convert to integral types, while conversion from an arbitrary integer back to an enumeration needs explicit care. Named enumerators need not have consecutive values.

An integer matching the underlying representation is not automatically a recognized domain choice. Validate the accepted codes instead of treating every integer as an enum value.

## Your mission

Implement permissionValue(permission), returning its integer code, and permissionFromCode(code), accepting exactly codes 0/1/2/4 and returning none/readPermission/writePermission/admin respectively. Unknown codes return none. Do not cast unchecked arbitrary integers into the enum. The enumerators use explicit nonconsecutive values.

## Expected behavior

- `permissionValue(admin) -> 4`
- `permissionFromCode(2) -> writePermission`
- `permissionFromCode(3) -> none`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.3`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Unscoped enumerator integral conversions](https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/)
