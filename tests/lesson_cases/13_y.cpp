#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for(int reading : {-20,0,5,10,20}) for(int low : {-5,0,10}) for(int high : {-5,0,10}) {
        const int lo{low<high?low:high},hi{low<high?high:low};
        Lab::eq(boundedTemperature(reading,low,high),reading<lo?lo:reading>hi?hi:reading,"normalized clamping bounds");
    }
    return Lab::finish();
}
