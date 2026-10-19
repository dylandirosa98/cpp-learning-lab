#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::expect(!fitsInBudget(-1,100u), "negative cost is invalid, not a huge unsigned cost");
    Lab::expect(!fitsInBudget(-1,std::numeric_limits<unsigned int>::max()), "negative cost remains invalid at maximum budget");
    Lab::expect(fitsInBudget(0,0u), "zero fits zero");
    Lab::expect(fitsInBudget(100,100u), "equal endpoint");
    Lab::expect(!fitsInBudget(101,100u), "over budget");
    Lab::expect(fitsInBudget(200,std::numeric_limits<unsigned int>::max()), "large unsigned budget");
    return Lab::finish();
}
