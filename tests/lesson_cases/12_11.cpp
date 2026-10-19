#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int a{3},b{8}; int* active{&a}; redirect(active,&b); Lab::expect(active==&b,"caller pointer redirected");
    Lab::eq(a,3,"old pointee unchanged"); Lab::eq(b,8,"new pointee unchanged");
    redirect(active,nullptr); Lab::expect(active==nullptr,"redirect to null");
    redirect(active,&a); Lab::expect(active==&a,"redirect from null");
    return Lab::finish();
}
