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
        const int result{readQuantity()};
        std::cin.rdbuf(previous);
        std::cin.clear();
        return result;
    };
    Lab::eq(readFrom("hello\n0\n8\n"), 8, "recover from text and range error");
    Lab::eq(readFrom("21\n1\n"), 1, "upper-bound rejection and lower-bound acceptance");
    Lab::eq(readFrom("20"), 20, "valid final token without newline");
    Lab::eq(readFrom("3 extra\n"), 3, "discard trailing text after integer");
    Lab::eq(readFrom("999999999999999999999999\n7\n"), 7, "recover from integer overflow");
    Lab::eq(readFrom(""), -1, "immediate EOF");
    Lab::eq(readFrom("bad\n-3\n"), -1, "EOF after invalid attempts");
    Lab::eq(readFrom("   "), -1, "whitespace-only EOF");
    return Lab::finish();
}
