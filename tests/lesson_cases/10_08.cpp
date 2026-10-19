#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int low : {-1000000,-4,0,1,4}) for (int high : {-4,0,1,4,1000000})
        Lab::near(midpoint(low,high),(static_cast<double>(low)+high)/2.0,"midpoint endpoints");
    return Lab::finish();
}
