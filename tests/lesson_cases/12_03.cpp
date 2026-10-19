#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int value{4}; int& alias{value}; addTo(value,3); Lab::eq(value,7,"modify caller");
    addTo(alias,-2); Lab::eq(value,5,"reference aliases same object");
    addTo(value,0); Lab::eq(value,5,"zero delta");
    return Lab::finish();
}
