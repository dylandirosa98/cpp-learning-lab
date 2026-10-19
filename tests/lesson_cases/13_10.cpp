#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Stats a{2,1},b{1,3}; const auto c{combine(a,b)}; Lab::eq(c.wins,3,"combined wins"); Lab::eq(c.losses,4,"combined losses");
    Lab::eq(a.wins,2,"left unchanged"); Lab::eq(b.losses,3,"right unchanged");
    Lab::near(winRate(Stats{1,3}),0.25,"fractional rate"); Lab::near(winRate(Stats{}),0.0,"empty rate");
    Lab::near(winRate(Stats{3,0}),1.0,"all wins"); Lab::near(winRate(Stats{0,3}),0.0,"all losses");
    return Lab::finish();
}
