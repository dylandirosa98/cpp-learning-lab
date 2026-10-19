#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int value : {-5,0,7,100}) {
        Lab::eq(scaleBy<3>(value),3*value,"positive template factor");
        Lab::eq(scaleBy<0>(value),0,"zero template factor");
        Lab::eq(scaleBy<-2>(value),-2*value,"negative template factor");
        Lab::eq(scaleBy<1>(value),value,"identity template factor");
    }
    return Lab::finish();
}
