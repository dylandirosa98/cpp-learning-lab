#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(shippingCost(5),10,"both defaults"); Lab::eq(shippingCost(5,3),30,"rate default only");
    Lab::eq(shippingCost(5,3,4),60,"no defaults"); Lab::eq(shippingCost(0),0,"zero distance");
    Lab::eq(shippingCost(-1),-1,"negative distance"); Lab::eq(shippingCost(5,0),-1,"no packages");
    Lab::eq(shippingCost(5,1,-1),-1,"negative rate"); Lab::eq(shippingCost(5,2,0),0,"free rate");
    return Lab::finish();
}
