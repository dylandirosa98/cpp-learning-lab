#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (double value : {-10000.0,-100.1,-100.0,-9.9,-0.9,0.0,0.9,9.9,100.0,100.1,10000.0}) {
        const int expected{value < -100 ? -100 : value > 100 ? 100 : static_cast<int>(value)};
        Lab::eq(wholeDegrees(value), expected, "wholeDegrees(" + std::to_string(value) + ")");
    }
    return Lab::finish();
}
