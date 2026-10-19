#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    std::string name{"Ada"}; Lab::eq(appendTag(name,"cpp"),std::string{"Ada[cpp]"},"tagged copy");
    Lab::eq(name,std::string{"Ada"},"caller remains unchanged");
    Lab::eq(appendTag("",""),std::string{"[]"},"empty fields");
    Lab::eq(appendTag("two words","x y"),std::string{"two words[x y]"},"preserve spaces");
    return Lab::finish();
}
