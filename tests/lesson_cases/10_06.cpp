#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::near(successRate(1,4),25.0,"1 of 4"); Lab::near(successRate(1,8),12.5,"1 of 8");
    Lab::near(successRate(0,5),0.0,"none succeeded"); Lab::near(successRate(5,5),100.0,"all succeeded");
    for (int attempts : {-1,0,1,7}) for (int successes : {-1,0,1,8}) {
        const double expected{attempts <= 0 || successes < 0 || successes > attempts ? -1.0 : static_cast<double>(successes) / attempts * 100.0};
        Lab::near(successRate(successes,attempts),expected,"validated percentage");
    }
    return Lab::finish();
}
