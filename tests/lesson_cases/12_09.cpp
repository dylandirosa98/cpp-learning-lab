#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    const int source{4}; int target{9}; Lab::expect(copyIfPresent(&source,&target),"valid copy"); Lab::eq(target,4,"destination changed");
    Lab::expect(!copyIfPresent(nullptr,&target),"null source"); Lab::eq(target,4,"failed copy preserves destination");
    Lab::expect(!copyIfPresent(&source,nullptr),"null destination"); Lab::expect(!copyIfPresent(nullptr,nullptr),"both null");
    Lab::expect(copyIfPresent(&target,&target),"same object copy"); Lab::eq(target,4,"self-copy unchanged");
    return Lab::finish();
}
