# 9.x: Chapter 9 summary and quiz

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

**Route:** Learn → predict → code → run tests → explain → submit.

This experimental chapter uses a guided, challenge-first lesson format. Everything needed for the mission is in this folder; external reading is optional enrichment.

## Capstone: a tiny order-processing service

Combine the chapter skills into three independently testable functions: a range-aware input reader, a pure pricing calculation, and a coordinator. This is a small service boundary: input mechanics do not belong inside the pricing formula, and pricing does not belong inside stream recovery.

## Contract before implementation

The product codes are 1, 2, and 3, with prices 5, 8, and 12. Quantities are 1 through 20. Invalid direct pricing calls return -1; interactive bad lines cause another read; input exhaustion stops the whole workflow with -1. Those are different failure policies for different layers.

## Trace a recovery sequence

For input bad, then 2, then 0, then 3: the reader discards the invalid product line, accepts product 2, rejects quantity 0, and accepts quantity 3. It should not reread product 2 when quantity fails. The final total is 8*3=24. EOF between the two valid reads must not reuse a stale quantity.

## Acceptance checklist

Read the visible tests before coding. Implement the pure pricing function, then the input reader, then coordination. Test valid endpoints, both kinds of invalid input, overflow recovery, EOF at each stage, and a final valid token without newline. Alt+R runs the tests without submission. Only the course checker records completion and synchronizes it.

## Reflect

Which function would change if the interface stopped using std::cin? Which would change if product prices changed? Explain why those are not the same responsibility.

## Your mission

Build a resilient order workflow. readBounded(low,high) follows 9.5 line-reading rules but accepts the inclusive bounds; return -1 on EOF or low > high. orderTotal(code,quantity) accepts product codes 1/2/3 priced at 5/8/12 and quantities 1..20; invalid values return -1. placeOrder() reads a product in [1,3], then quantity in [1,20], and returns the total, or -1 if input ends. Do not print prompts or totals; return the result. Retrying a quantity must not reread the product.

## Expected behavior

- `orderTotal(2,3) -> 24`
- `orderTotal(4,3) -> -1`
- `placeOrder with "bad\n2\n0\n3\n" -> 24`
- `placeOrder with "1\n" -> -1`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 9.x`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Chapter 9 summary and quiz](https://www.learncpp.com/cpp-tutorial/chapter-9-summary-and-quiz/)
