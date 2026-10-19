# 13.x: Chapter 13 summary and quiz

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

## Learn the idea

Use a scoped enum for domain outcomes, a struct for related result data, and a reference for the object being intentionally mutated. Each part of the signature communicates a different responsibility.

Validate before mutating so failed operations preserve caller state. Tests should inspect both the returned result and the original inventory after every success and failure.

## Your mission

Implement sell(inventory,quantity,unitPrice), returning SaleResult. Invalid quantity <= 0 or unitPrice < 0 returns {SaleError::invalid,0,currentStock}. If quantity exceeds stock return {SaleError::shortStock,0,currentStock}. Otherwise reduce stock, increase cash by quantity*unitPrice, and return {SaleError::ok,total,newStock}. On failure leave inventory unchanged. Initial stock/cash are nonnegative and tested arithmetic fits int. Free items (unitPrice=0) are valid.

## Expected behavior

- `Inventory{5,10}, sell(...,2,3) -> stock 3, cash 16, result {ok,6,3}`
- `too many items -> shortStock, unchanged inventory`
- `zero quantity -> invalid, unchanged inventory`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 13.x`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Chapter 13 summary and quiz](https://www.learncpp.com/cpp-tutorial/chapter-13-summary-and-quiz/)
