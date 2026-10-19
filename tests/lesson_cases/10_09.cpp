#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    static_assert(std::is_same_v<decltype(absoluteGap(1,2)), int>);
    for (int left : {-1000000,-4,0,3,8}) for (int right : {-4,0,3,8,1000000})
        Lab::eq(absoluteGap(left,right), left < right ? right-left : left-right, "symmetric integer distance");
    return Lab::finish();
}
