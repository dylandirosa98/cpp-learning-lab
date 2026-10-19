# 9.2: Code coverage

Original personal-study companion. Not affiliated with Boot.dev or LearnCpp.

**Route:** Learn → predict → code → run tests → explain → submit.

This experimental chapter uses a guided, challenge-first lesson format. Everything needed for the mission is in this folder; external reading is optional enrichment.

## Learn: coverage is a map, not a proof

Statement coverage records whether each executable statement ran. Branch coverage asks whether each decision outcome ran. Coverage can reveal missing tests, but passing coverage metrics do not prove the threshold values or formulas are correct. A line can run with an unrepresentative input.

## Worked example: the weight boundary

If a package of weight 5 uses the first price bracket and weight 6 uses the second, testing only weights 2 and 10 can miss an accidental strict comparison at 5. Test just below, exactly at, and just above important thresholds. The invalid-weight branch must be tested independently too.

## Mission strategy

List weight categories first: invalid, light, medium, heavy. Cross them with ordinary and express shipping. Trace which decisions each example exercises. This is a small enough domain to test every meaningful combination without randomness. Do not add the express fee to an error sentinel.

## Reflect

Can every branch run while a boundary bug remains? Why test express=true for invalid weight even though invalid weight is already tested with express=false?

## Your mission

Implement shippingFee(weight, express). Weight <= 0 is invalid and returns -1, even for express. Valid weights 1..5 cost 5, weights 6..20 cost 10, and larger weights cost 20. Express adds 7 only to valid orders. Test both express choices in every weight category and directly on the 5/6 and 20/21 boundaries.

## Expected behavior

- `shippingFee(5,false) -> 5`
- `shippingFee(6,true) -> 17`
- `shippingFee(21,false) -> 20`
- `shippingFee(0,true) -> -1`

## Work in Neovim

1. Open `main.cpp` (and any helper header named in the mission).
2. Read the visible tests at the bottom and predict the first failing case.
3. Implement the TODO bodies/API. Do not replace the tests with printed answers.
4. Save and press **Alt+R** with your configured CMake runner. No submission occurs.
5. Fix the first reported failure, rerun, and then add a test of your own.
6. Use `hints.md` only if stuck. Compare with the reference solution after a genuine attempt.

From the repository root, submit with `./course check 9.2`. It runs the independent tests, saves completion only on success, and syncs course work. Compilation errors are valid feedback for lessons about type interfaces or constant expressions.

## What is graded?

Returned values, mutations, object identity, stream state, and any public type/compile-time requirements explicitly stated above. No exact source-token checks or arbitrary console labels. The visible tests and independent checker cover the same required cases. If your added test finds a missing edge case, keep it.

## Continue reading

[LearnCpp: Code coverage](https://www.learncpp.com/cpp-tutorial/code-coverage/)
