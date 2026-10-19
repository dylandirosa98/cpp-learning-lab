#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::expect(sameValue(2,2),"equal integers"); Lab::expect(!sameValue(-2,2),"different integers");
    Lab::expect(sameValue(std::string_view{"cat"},std::string_view{"cat"}),"equal contents");
    Lab::expect(!sameValue(std::string_view{"cat"},std::string_view{"Cat"}),"case-sensitive contents");
    Lab::expect(sameValue(std::string_view{},std::string_view{}),"empty contents");
    std::string copied{"cat"}; Lab::expect(sameValue(std::string_view{copied},std::string_view{"cat"}),"different storage, same contents");
    return Lab::finish();
}
