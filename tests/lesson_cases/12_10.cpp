#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int n{9}; resetIfPresent(&n); Lab::eq(n,0,"reset caller");
    n=-8; resetIfPresent(&n); Lab::eq(n,0,"reset negative caller");
    resetIfPresent(nullptr); Lab::expect(true,"null call returned safely");
    return Lab::finish();
}
