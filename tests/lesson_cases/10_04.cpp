#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (int value : {-1000,-1,0,1,127,128,254,255,256,1000})
        Lab::eq(static_cast<int>(clampChannel(value)), value < 0 ? 0 : value > 255 ? 255 : value, "channel=" + std::to_string(value));
    return Lab::finish();
}
