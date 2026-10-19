#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(turnRight(north),east,"north turns east"); Lab::eq(turnRight(east),south,"east turns south");
    Lab::eq(turnRight(south),west,"south turns west"); Lab::eq(turnRight(west),north,"west wraps north");
    Direction d{north}; for(int i{0};i<4;++i) d=turnRight(d); Lab::eq(d,north,"four turns complete a circle");
    return Lab::finish();
}
