#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(valueOr(nullptr,7),7,"null uses fallback"); int n{0}; Lab::eq(valueOr(&n,7),0,"pointed zero is not null");
    n=-3; Lab::eq(valueOr(&n,7),-3,"pointed negative value"); Lab::eq(n,-3,"pointee unchanged");
    Lab::eq(valueOr(nullptr,-1),-1,"negative fallback");
    return Lab::finish();
}
