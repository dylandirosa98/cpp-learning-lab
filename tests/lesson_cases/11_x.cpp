#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(clampValue(-1,0,10),0,"below lower bound"); Lab::eq(clampValue(12,0,10),10,"above upper bound");
    Lab::eq(clampValue(5,0,10),5,"inside interval"); Lab::eq(clampValue(5,3,3),3,"single-value interval");
    Lab::near(clampValue(0.25,0.0,1.0),0.25,"double interval"); Lab::near(clampValue(2.0,0.0,1.0),1.0,"double clamp");
    Lab::near(discounted<25>(10),7.5,"integer price keeps fraction");
    Lab::near(discounted<0>(1.25),1.25,"no discount"); Lab::near(discounted<100>(25),0.0,"full discount");
    Lab::near(discounted<10>(9.99),8.991,"floating price");
    return Lab::finish();
}
