#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::near(sumAsDouble(-3,2u),-1.0,"mixed signed and unsigned");
    Lab::near(sumAsDouble(2,0.5),2.5,"integer and double");
    Lab::near(sumAsDouble(1.25,2),3.25,"double and integer");
    Lab::near(sumAsDouble(0u,-2),-2.0,"reverse signedness");
    Lab::near(sumAsDouble(2u,3u),5.0,"same unsigned type");
    return Lab::finish();
}
