#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{10},b{3}; auto result{transfer(&a,&b,4)}; Lab::eq(result.value_or(-1),6,"new source balance");
    Lab::eq(a,6,"debit"); Lab::eq(b,7,"credit");
    Lab::expect(!transfer(&a,&b,99).has_value(),"insufficient funds"); Lab::eq(a,6,"failed debit unchanged"); Lab::eq(b,7,"failed credit unchanged");
    Lab::expect(!transfer(&a,&a,1).has_value(),"self transfer rejected");
    Lab::expect(!transfer(nullptr,&b,1).has_value(),"null source"); Lab::expect(!transfer(&a,nullptr,1).has_value(),"null destination");
    Lab::expect(!transfer(&a,&b,-1).has_value(),"negative amount");
    Lab::eq(transfer(&a,&b,0).value_or(-1),6,"zero transfer succeeds");
    Lab::eq(transfer(&a,&b,6).value_or(-1),0,"engaged zero after emptying source"); Lab::eq(b,13,"conserved funds");
    int bad{-2}; Lab::expect(!transfer(&bad,&b,0).has_value(),"negative source balance");
    Lab::expect(!transfer(&b,&bad,0).has_value(),"negative destination balance"); Lab::eq(b,13,"invalid account leaves valid balance untouched");
    return Lab::finish();
}
