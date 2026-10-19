# 13.5: Introduction to overloading the I/O operators

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Overloaded stream operators let program-defined types participate in ordinary extraction and insertion syntax. Return the same stream reference to preserve chaining and its error state.

Extraction should not silently invent a valid value when parsing fails. Read into temporary storage, validate it, and only then assign the caller's object.

## Your mission

Implement operator<< and operator>> for Color. Output exactly the lowercase color name with no newline. Input extracts one whitespace-delimited word; recognized names update color, unknown words set failbit and leave color unchanged. Failed extraction also leaves color unchanged. Return the original stream reference from both operators so chaining works. Unlike most challenges, text format is the actual API being exercised here.

## Expected behavior

- `out << red << " " << blue -> "red blue"`
- `input "green" -> green and success`
- `input "purple" -> failbit, old value preserved`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.5`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Introduction to overloading the I/O operators](https://www.learncpp.com/cpp-tutorial/introduction-to-overloading-the-i-o-operators/)
