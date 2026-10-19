#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (char c{'0'}; c <= '9'; ++c) {
        const auto digit{parseDigit(c)}; Lab::expect(digit.has_value(),"digit is engaged");
        Lab::eq(digit.value_or(-99),c-'0',"decoded digit");
    }
    for (char c : {'x','/',' ',':','-','A'}) Lab::expect(!parseDigit(c).has_value(),"nondigit has no value");
    return Lab::finish();
}
