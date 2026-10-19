#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Pair<int> integers{2,3}; Lab::eq(pairSum(integers),5,"integer class template");
    Pair<double> fractions{1.25,2.5}; Lab::near(pairSum(fractions),3.75,"double member types");
    Pair<int> empty{}; Lab::eq(empty.first,0,"first value initialization"); Lab::eq(empty.second,0,"second value initialization");
    Lab::eq(pairSum(Pair<int>{-3,1}),-2,"negative pair sum");
    return Lab::finish();
}
