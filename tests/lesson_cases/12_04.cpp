#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    const int a{3}, b{8}; Lab::eq(maxReadOnly(a,b),8,"const lvalues");
    Lab::eq(a,3,"first input unchanged"); Lab::eq(b,8,"second input unchanged");
    Lab::eq(maxReadOnly(9,2),9,"temporary arguments"); Lab::eq(maxReadOnly(-2,-4),-2,"negative arguments");
    Lab::eq(maxReadOnly(7,7),7,"equal arguments");
    return Lab::finish();
}
