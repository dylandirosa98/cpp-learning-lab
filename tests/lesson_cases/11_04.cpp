#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"
template <typename T> concept AcceptsWhole = requires(T value) { wholeUnits(value); };
int main()
{
    static_assert(AcceptsWhole<int>, "int must be accepted");
    static_assert(!AcceptsWhole<double>, "double must be rejected by the API");
    Lab::eq(wholeUnits(7),7,"whole units"); Lab::eq(wholeUnits(0),0,"zero units"); Lab::eq(wholeUnits(-1),0,"negative input");
    return Lab::finish();
}
