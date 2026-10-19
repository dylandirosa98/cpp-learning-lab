#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::expect(isLeapYear(2024), "2024 is divisible by 4, not 100");
    Lab::expect(!isLeapYear(2023), "2023 is ordinary");
    Lab::expect(!isLeapYear(1900), "1900 is the century exception");
    Lab::expect(isLeapYear(2000), "2000 is the 400-year exception");
    Lab::expect(!isLeapYear(0), "zero is outside this exercise's domain");
    Lab::expect(!isLeapYear(-400), "negative years are invalid");
    for (int year{1}; year <= 2400; ++year) {
        const bool expected{year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)};
        Lab::eq(isLeapYear(year), expected, "calendar rule for year " + std::to_string(year));
    }
    return Lab::finish();
}
