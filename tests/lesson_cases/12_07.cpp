#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{4}; doublePointed(&a); Lab::eq(a,8,"pointed positive value");
    int b{-3}; doublePointed(&b); Lab::eq(b,-6,"pointed negative value");
    int c{0}; doublePointed(&c); Lab::eq(c,0,"pointed zero");
    return Lab::finish();
}
