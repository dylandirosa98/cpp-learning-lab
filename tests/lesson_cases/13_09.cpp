#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for(int retries : {-5,-1,0,1,5}) {
        const auto c{configured(retries)}; Lab::eq(c.timeout,30,"default timeout preserved");
        Lab::eq(c.retries,retries<0?3:retries,"validated retry override"); Lab::expect(c.secure,"default security preserved");
    }
    return Lab::finish();
}
