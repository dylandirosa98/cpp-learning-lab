#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(invoiceTotal(999,3,10),2697LL,"round once after the full subtotal");
    for (Cents price : {-1LL,0LL,1LL,999LL,1000000LL}) for (int quantity : {-1,0,1,3,1000}) for (int discount : {-1,0,10,100,101}) {
        const Cents expected{price < 0 || quantity < 0 || discount < 0 || discount > 100 ? -1 : price*quantity*(100-discount)/100};
        Lab::eq(invoiceTotal(price,quantity,discount),expected,"validated invoice");
    }
    for (Cents cents : {-125LL,-50LL,0LL,1LL,125LL,999999LL}) Lab::near(currencyUnits(cents),cents/100.0,"currency conversion");
    return Lab::finish();
}
