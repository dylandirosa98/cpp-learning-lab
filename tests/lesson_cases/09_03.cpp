#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::near(averageScore(5,2), 2.5, "fractional average, not integer division");
    Lab::near(averageScore(1,4), 0.25, "small fraction");
    Lab::near(averageScore(0,3), 0.0, "zero total is valid");
    Lab::near(averageScore(99,1), 99.0, "one entry");
    Lab::near(averageScore(5,0), -1.0, "zero count");
    Lab::near(averageScore(5,-2), -1.0, "negative count");
    Lab::near(averageScore(-1,2), -1.0, "negative total");
    return Lab::finish();
}
