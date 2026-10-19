#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int cm : {-10,-1,0,1,99,100,125,999,1000000})
        Lab::near(metersFromCentimeters(cm), cm < 0 ? -1.0 : cm / 100.0, "centimeters=" + std::to_string(cm));
    return Lab::finish();
}
