# Course checker

Source checks ignore clang-format whitespace around `{` and `}`. `{6}` and `{ 6 }` are the same. Do not fail a lesson on brace spacing. Keep this for chapter 5 and every later chapter.

They still require the actual tokens: `unsigned int` is not `uint`, `const float` is not `double`. Output must still match exactly.
