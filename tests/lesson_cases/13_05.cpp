#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    std::ostringstream output; Lab::expect(&(output<<red)==&output,"output returns same stream");
    output<<" "<<green<<" "<<blue; Lab::eq(output.str(),std::string{"red green blue"},"chain formatted colors");
    std::istringstream input{"green blue"}; Color first{red},second{red};
    Lab::expect(&(input>>first)==&input,"input returns same stream"); input>>second;
    Lab::expect(!input.fail(),"known colors parse"); Lab::eq(first,green,"first token"); Lab::eq(second,blue,"second token");
    std::istringstream bad{"purple"}; Color old{green}; bad>>old; Lab::expect(bad.fail(),"unknown color sets failbit"); Lab::eq(old,green,"unknown token preserves object");
    std::istringstream empty{""}; empty>>old; Lab::expect(empty.fail(),"empty extraction fails"); Lab::eq(old,green,"EOF preserves object");
    return Lab::finish();
}
