#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int left : {-100,-1,0,1,100}) for (int right : {-30000,-20,0,20,30000})
        Lab::eq(addSmall(static_cast<signed char>(left), static_cast<short>(right)), left+right, "promoted addition");
    return Lab::finish();
}
