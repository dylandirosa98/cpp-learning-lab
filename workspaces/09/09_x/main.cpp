/*
Lesson 9.x - Chapter 9 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-9-summary-and-quiz/

Problem:
Build a resilient order workflow. readBounded(low,high) follows 9.5 line-reading rules but
accepts the inclusive bounds; return -1 on EOF or low > high. orderTotal(code,quantity) accepts
product codes 1/2/3 priced at 5/8/12 and quantities 1..20; invalid values return -1.
placeOrder() reads a product in [1,3], then quantity in [1,20], and returns the total, or -1 if
input ends. Do not print prompts or totals; return the result. Retrying a quantity must not
reread the product.

Expected results (examples):
- orderTotal(2,3) -> 24
- orderTotal(4,3) -> -1
- placeOrder with "bad\n2\n0\n3\n" -> 24
- placeOrder with "1\n" -> -1

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 9.x
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_09_x
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>
#include <limits>
#include <sstream>



int readBounded(int low, int high)
{
    // TODO: Implement the contract above.
    (void)low; (void)high; return 0;
}

int orderTotal(int code, int quantity)
{
    // TODO: Implement the contract above.
    (void)code; (void)quantity; return 0;
}

int placeOrder()
{
    // TODO: Implement the contract above.
    return 0;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    auto readFrom = [](const std::string& input) {
        std::istringstream source{input};
        auto* previous{std::cin.rdbuf(source.rdbuf())};
        std::cin.clear();
        const int result{placeOrder()};
        std::cin.rdbuf(previous);
        std::cin.clear();
        return result;
    };
    Lab::eq(readFrom("bad\n2\n0\n3\n"), 24, "recover product and quantity independently");
    Lab::eq(readFrom("3\n20"), 240, "maximum quantity and no final newline");
    Lab::eq(readFrom("1\n"), -1, "EOF before quantity");
    Lab::eq(readFrom(""), -1, "EOF before product");
    for (int code{-1}; code <= 5; ++code)
        for (int quantity{-1}; quantity <= 22; ++quantity) {
            const int expected{code < 1 || code > 3 || quantity < 1 || quantity > 20 ? -1 : quantity * (code == 1 ? 5 : code == 2 ? 8 : 12)};
            Lab::eq(orderTotal(code,quantity), expected, "orderTotal code=" + std::to_string(code) + ", quantity=" + std::to_string(quantity));
        }
    Lab::eq(readBounded(5,1), -1, "reversed input bounds must not read stdin");
    {
        std::istringstream source{"bad\n-3\n-2\n"};
        auto* previous{std::cin.rdbuf(source.rdbuf())}; std::cin.clear();
        Lab::eq(readBounded(-2,0), -2, "general bounds, not hard-coded quantity bounds");
        std::cin.rdbuf(previous); std::cin.clear();
    }
    return Lab::finish();
}
#endif
