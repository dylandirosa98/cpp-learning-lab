#include <iostream>

unsigned int issueTicket()
{
    static unsigned int s_nextTicket{ 100 };
    return s_nextTicket++;
}

int main()
{
    std::cout << "Ticket: " << issueTicket() << '\n';
    std::cout << "Ticket: " << issueTicket() << '\n';
    std::cout << "Ticket: " << issueTicket() << '\n';
    return 0;
}
