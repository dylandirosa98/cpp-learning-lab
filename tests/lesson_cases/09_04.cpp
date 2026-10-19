#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int value{-2}; value <= 30; ++value)
        for (int divisor{-2}; divisor <= 9; ++divisor)
            Lab::eq(safeRemainder(value, divisor), value < 0 || divisor <= 0 ? -1 : value % divisor,
                "value=" + std::to_string(value) + ", divisor=" + std::to_string(divisor));
    return Lab::finish();
}
