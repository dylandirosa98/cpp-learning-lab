# Course checker

Source checks ignore all formatting whitespace: line wraps, indentation,
brace placement, and spacing around braces/operators. `int main()\n{` and
`int main() {` are the same, as are `{6}`, `{ 6 }`, `a+b`, and `a + b`.
Never fail a lesson on formatting alone, in any current or future lesson.
Keep this for chapter 5 and every later chapter.

They still require the actual tokens: `unsigned int` is not `uint`, `const float` is not `double`, `std::string` is not `std::string_view`. Output must still match exactly.

Chapter 8 random lessons (8.13-8.15) pin expected output to fixed-seed `std::mt19937` draws and power-of-two distribution ranges (a four-sided die, a coin flip). Raw engine output is fully specified, and power-of-two ranges map identically across standard library implementations, so the exact output never depends on the compiler or library version. Keep it that way: never add a lesson whose checked output depends on `std::uniform_int_distribution` with a non-power-of-two range, on `std::uniform_real_distribution`, or on `std::rand`.
