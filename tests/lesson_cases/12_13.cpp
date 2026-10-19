#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int n : {-17,-1,0,1,17}) for (int d : {-5,-1,0,1,5}) {
        int q{123},r{456}; const bool ok{divideWithRemainder(n,d,q,r)};
        const std::string input{"numerator=" + std::to_string(n) + ", denominator=" + std::to_string(d)};
        Lab::eq(ok,d!=0,input + ": success status");
        Lab::eq(q,d==0?123:n/d,input + ": quotient or preserved output 123");
        Lab::eq(r,d==0?456:n%d,input + ": remainder or preserved output 456");
    }
    return Lab::finish();
}
