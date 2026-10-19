#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(maxOf(3,8),8,"int maximum"); Lab::eq(maxOf(8,3),8,"reversed maximum");
    Lab::eq(maxOf(-4,-2),-2,"negative maximum"); Lab::eq(maxOf(7,7),7,"equal values");
    Lab::near(maxOf(1.5,1.25),1.5,"double maximum");
    Lab::eq(maxOf(std::string{"ant"},std::string{"bee"}),std::string{"bee"},"string maximum");
    return Lab::finish();
}
