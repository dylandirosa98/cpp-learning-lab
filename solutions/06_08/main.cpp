#include <iostream>

bool canEnter(bool hasBadge, bool isStaff, bool hasAppointment, bool isSuspended)
{
    return hasBadge && (isStaff || hasAppointment) && !isSuspended;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Appointed visitor: " << canEnter(true, false, true, false) << '\n';
    std::cout << "Staff without badge: " << canEnter(false, true, false, false) << '\n';
    std::cout << "Suspended staff: " << canEnter(true, true, false, true) << '\n';
    return 0;
}
