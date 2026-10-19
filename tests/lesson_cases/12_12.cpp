#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{3},b{8}; Lab::expect(&largerRef(a,b)==&b,"return larger object's identity");
    largerRef(a,b)=20; Lab::eq(b,20,"assignment through returned reference"); Lab::eq(a,3,"other object unchanged");
    int c{5},d{5}; Lab::expect(&largerRef(c,d)==&c,"ties choose first identity");
    Lab::expect(&largerRef(a,a)==&a,"same object twice");
    return Lab::finish();
}
