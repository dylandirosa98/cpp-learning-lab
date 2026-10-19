#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Point p{2,3}; const auto moved{translated(p,4,-1)}; Lab::eq(moved.x,6,"translated x"); Lab::eq(moved.y,2,"translated y");
    Lab::eq(p.x,2,"original x unchanged"); Lab::eq(p.y,3,"original y unchanged");
    const auto zero{translated(Point{-5,8},0,0)}; Lab::eq(zero.x,-5,"zero dx"); Lab::eq(zero.y,8,"zero dy");
    const auto origin{translated(Point{2,3},-2,-3)}; Lab::eq(origin.x,0,"translate to origin x"); Lab::eq(origin.y,0,"translate to origin y");
    return Lab::finish();
}
