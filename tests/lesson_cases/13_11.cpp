#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Player p{"Ada",{2,3},90}; movePlayer(p,4,-1); Lab::eq(p.position.x,6,"nested x updated"); Lab::eq(p.position.y,2,"nested y updated");
    Lab::eq(p.name,std::string{"Ada"},"name preserved"); Lab::eq(p.health,90,"health preserved");
    movePlayer(p,-6,-2); Lab::eq(p.position.x,0,"nested x returns to origin"); Lab::eq(p.position.y,0,"nested y returns to origin");
    return Lab::finish();
}
