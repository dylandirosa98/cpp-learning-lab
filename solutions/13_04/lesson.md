# 13.4: Converting an enumeration to and from a string

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Enum-to-text conversion gives a domain value a user-facing name; text-to-enum conversion must also describe invalid input. An optional makes an unrecognized string distinct from every valid color.

Keep a precise normalization policy. Case sensitivity and whitespace rules must be stated rather than guessed by callers.

## Your mission

Implement colorName(color) and parseColor(text). Names are exactly lowercase "red", "green", "blue". parseColor returns an engaged optional<Color> for those names, otherwise nullopt; no whitespace trimming or case folding. colorName receives valid enumerators only. Returning string_view literals is safe because their storage lasts for the program.

## Expected behavior

- `colorName(green) -> "green"`
- `parseColor("blue") -> blue`
- `parseColor("Blue") -> nullopt`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.4`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Converting an enumeration to and from a string](https://www.learncpp.com/cpp-tutorial/converting-an-enumeration-to-and-from-a-string/)
