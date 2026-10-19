#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (Cents price : {-1LL,0LL,1LL,999LL,1000000LL}) for (int percent : {-1,0,10,50,100,101})
        Lab::eq(discountedPrice(price,percent), price < 0 || percent < 0 || percent > 100 ? -1LL : price*(100-percent)/100, "discounted integer cents");
    return Lab::finish();
}
