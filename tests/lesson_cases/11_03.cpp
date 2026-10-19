#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::near(scale(4),8.0,"int exact match"); Lab::near(scale(4.0),6.0,"double exact match");
    Lab::near(scale(char{4}),8.0,"char promotes to int"); Lab::near(scale(4.0f),6.0,"float promotes to double");
    Lab::near(scale(-3),-6.0,"negative integer"); Lab::near(scale(-0.5),-0.75,"negative double");
    return Lab::finish();
}
