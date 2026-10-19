#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
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
