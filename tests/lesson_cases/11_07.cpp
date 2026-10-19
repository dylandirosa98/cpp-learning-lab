#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(squared(5),25,"deduced int instance"); Lab::eq(squared<int>(-4),16,"explicit int instance");
    Lab::near(squared<double>(1.5),2.25,"explicit double instance");
    Lab::eq(squared<long long>(100000),10000000000LL,"wide instance must stay wide");
    Lab::eq(squared(0),0,"zero");
    return Lab::finish();
}
