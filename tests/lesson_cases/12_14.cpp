#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{1},b{2}; static_assert(std::is_same_v<decltype(selectCounter(a,b,true)),int&>);
    Lab::expect(&selectCounter(a,b,true)==&a,"first reference selected");
    Lab::expect(&selectCounter(a,b,false)==&b,"second reference selected");
    selectCounter(a,b,true)=7; selectCounter(a,b,false)=9; Lab::eq(a,7,"write through first"); Lab::eq(b,9,"write through second");
    return Lab::finish();
}
