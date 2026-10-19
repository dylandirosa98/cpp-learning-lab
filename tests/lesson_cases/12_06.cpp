#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    const std::string text{"cat"}; Lab::expect(longerThan(text,2),"strictly longer");
    Lab::expect(!longerThan(text,3),"equal length does not qualify"); Lab::expect(!longerThan(text,4),"shorter");
    Lab::expect(!longerThan(std::string{},0),"empty string"); Lab::eq(text,std::string{"cat"},"input unchanged");
    return Lab::finish();
}
