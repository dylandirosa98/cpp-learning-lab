#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(minOf(3,8),3,"header int instance"); Lab::near(minOf(1.5,1.25),1.25,"header double instance");
    Lab::eq(minimumFromOtherFile(8,3),3,"template instantiated by second source file");
    Lab::eq(minimumFromOtherFile(-4,-2),-4,"second source negative case");
    Lab::eq(minOf(std::string{"ant"},std::string{"bee"}),std::string{"ant"},"header string instance");
    return Lab::finish();
}
