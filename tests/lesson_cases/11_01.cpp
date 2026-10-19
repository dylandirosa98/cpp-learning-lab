#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    static_assert(std::is_same_v<decltype(doubleValue(1)),int>);
    static_assert(std::is_same_v<decltype(doubleValue(1.0)),double>);
    for (int value : {-100,-1,0,1,12345}) Lab::eq(doubleValue(value),value*2,"integer overload");
    for (double value : {-2.5,-0.25,0.0,1.25,100.1}) Lab::near(doubleValue(value),value*2,"double overload");
    return Lab::finish();
}
