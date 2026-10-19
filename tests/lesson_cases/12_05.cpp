#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{8}, b{3}; sortPair(a,b); Lab::eq(a,3,"smaller stored first"); Lab::eq(b,8,"larger stored second");
    sortPair(a,b); Lab::eq(a,3,"already sorted first"); Lab::eq(b,8,"already sorted second");
    sortPair(a,a); Lab::eq(a,3,"same object for both arguments");
    int c{-1},d{-9}; sortPair(c,d); Lab::eq(c,-9,"negative smaller"); Lab::eq(d,-1,"negative larger");
    return Lab::finish();
}
