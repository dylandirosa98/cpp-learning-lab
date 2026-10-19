#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for(int width : {-1,0,1,3,4}) for(int height : {-1,0,1,3,4}) {
        Rectangle r{width,height};
        Lab::eq(area(r),width<=0||height<=0?0:width*height,"rectangle area");
        Lab::eq(isSquare(r),width>0&&height>0&&width==height,"valid square classification");
    }
    return Lab::finish();
}
