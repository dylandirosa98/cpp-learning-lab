/*
Challenge: String to Integer (atoi) — LeetCode 8 style
Level: medium. Standalone (not part of ./course check).

Your toolbox: functions (ch 2), if/else (4.10), chars (4.11),
type conversion (4.12), strings/string_view (ch 5), operators (ch 6),
plus loops (your stretch skill — the course hasn't taught them yet).

RULES — implement int myAtoi(std::string_view s):
1. Ignore leading whitespace (' ' only — you don't need tabs).
2. Optional single '+' or '-' sign. Anything like "+-" means "no valid number" -> 0.
3. Read digits 0-9 until the first non-digit, then stop. ("4193 with words" -> 4193)
4. No digits at all ("" / "   " / "words 123" / "+-12") -> return 0.
5. Clamp overflow to 32-bit signed range instead of wrapping:
     >  2147483647 -> return 2147483647 (INT_MAX)
     < -2147483648 -> return -2147483648 (INT_MIN)
   Do the clamp DURING the loop (check before result * 10 + digit would
   overflow). Signed overflow is undefined behavior — never let it happen.
6. Do NOT use std::stoi / std::from_chars / stringstream. Hand-roll the loop.

Examples:
  myAtoi("42")                -> 42
  myAtoi("   -42")            -> -42
  myAtoi("4193 with words")   -> 4193
  myAtoi("words and 987")     -> 0
  myAtoi("-91283472332")      -> -2147483648 (clamped)

Build & run (from repo root):
  g++ -std=c++20 -Wall -Wextra workspaces/challenge_atoi/main.cpp -o /tmp/atoi && /tmp/atoi

TASKS:
1. Implement myAtoi below (the stub returns 0, so tests fail at first).
2. Get all 14 checks green without warnings.
3. Stretch: can you do the overflow check with only `int`, no `long long`?


*/
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string_view>

int myAtoi(std::string_view s) {
    std::string numberstring = {};
    long long number = {};
    bool signfound = false;
    bool negative = false;
    bool hitnumbers = false;
    for (int i = 0; i < static_cast<int>(s.length()); i++) {

        if (s[i] >= '0' && s[i] <= '9') {
            numberstring += s[i];
            hitnumbers = true;
        }

        else if (s[i] == '-' || s[i] == '+') {
            if (hitnumbers) {
                break;
            }
            if (signfound) {
                return 0;
            }
            signfound = true;
            if (s[i] == '-') {
                negative = true;
            }
        }

        else if (s[i] == ' ') {
            if (hitnumbers) {
                break;
            }
        }

        else {
            if (hitnumbers) {
                break;
            } else {
                return 0;
            }
        }
    }

    for (int i = 0; i < static_cast<int>(numberstring.length()); i++) {
        int num = numberstring[i] - '0';
        number += std::pow(10, (numberstring.length() - i - 1)) * num;
    }

    if (number > 2147483647 || (number == 2147483647 && negative == false)) {
        if (negative) {
            return INT_MIN;
        } else {
            return INT_MAX;
        }
    }

    if (negative) {
        return number * -1;
    }

    return number;
}

struct TestCase {
    std::string_view input;
    int expected;
};

int main() {
    const TestCase tests[]{
        {"42", 42},
        {"   -42", -42},
        {"4193 with words", 4193},
        {"words and 987", 0},
        {"-91283472332", INT_MIN},
        {"91283472332", INT_MAX},
        {"+1", 1},
        {"+-12", 0},
        {"00000-42a1234", 0},
        {"   +0 123", 0},
        {"2147483647", INT_MAX},
        {"2147483648", INT_MAX},
        {"-2147483648", INT_MIN},
        {"-2147483649", INT_MIN},
    };

    int passed{0};
    int total{0};
    for (const auto &t : tests) {
        ++total;
        const int got{myAtoi(t.input)};
        const bool ok{got == t.expected};
        if (ok)
            ++passed;
        std::cout << (ok ? "PASS" : "FAIL") << " myAtoi(\"" << t.input << "\") = " << got
                  << " (expected " << t.expected << ")\n";
    }

    std::cout << passed << '/' << total << " passed\n";
    return (passed == total) ? 0 : 1;
}
