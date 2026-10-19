#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Counter c{4}; Lab::expect(incrementCounter(&c,3),"valid counter"); Lab::eq(c.value,7,"pointer member updated");
    Lab::expect(incrementCounter(&c,-2),"negative delta"); Lab::eq(c.value,5,"negative update");
    Lab::expect(incrementCounter(&c,0),"zero delta succeeds"); Lab::expect(!incrementCounter(nullptr,5),"null counter rejected");
    return Lab::finish();
}
