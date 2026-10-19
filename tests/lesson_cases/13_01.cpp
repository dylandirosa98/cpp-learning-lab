#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Money a{125},b{75}; Lab::eq(addMoney(a,b).cents,200,"sum of cents");
    Lab::eq(a.cents,125,"left unchanged"); Lab::eq(b.cents,75,"right unchanged");
    Lab::eq(addMoney(Money{-50},Money{25}).cents,-25,"negative adjustment");
    Lab::eq(addMoney(Money{0},Money{0}).cents,0,"zero money");
    return Lab::finish();
}
