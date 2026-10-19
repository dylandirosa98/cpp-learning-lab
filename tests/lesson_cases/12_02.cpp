#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    int ticket{4}; Lab::eq(nextTicket(ticket),5,"named lvalue argument");
    Lab::eq(ticket,4,"value parameter does not mutate caller");
    Lab::eq(nextTicket(4),5,"literal rvalue argument"); Lab::eq(nextTicket(2+3),6,"expression rvalue argument");
    Lab::eq(nextTicket(-1),0,"negative ticket");
    return Lab::finish();
}
