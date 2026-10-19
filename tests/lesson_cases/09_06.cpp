#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    static_assert(validPercent(0) && validPercent(100));
    static_assert(!validPercent(-1) && !validPercent(101));
    for (int value : {0, 1, 50, 99, 100}) Lab::eq(checkedPercent(value), value, "valid assertion precondition");
    Lab::expectAbort([] { checkedPercent(-1); }, "negative percent must trigger assert");
    Lab::expectAbort([] { checkedPercent(101); }, "percent above 100 must trigger assert");
    return Lab::finish();
}
