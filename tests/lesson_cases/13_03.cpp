#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(permissionValue(none),0,"none code"); Lab::eq(permissionValue(readPermission),1,"read code");
    Lab::eq(permissionValue(writePermission),2,"write code"); Lab::eq(permissionValue(admin),4,"nonconsecutive admin code");
    for(int code{-3};code<=8;++code) Lab::eq(permissionFromCode(code),code==1?readPermission:code==2?writePermission:code==4?admin:none,"validated permission code="+std::to_string(code));
    return Lab::finish();
}
