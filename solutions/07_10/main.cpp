#include "time_constants.h"

#include <iostream>

int workdayMinutes();

int main()
{
    constexpr int meetingMinutes{ timeConstants::minutesPerHour + timeConstants::minutesPerHour / 2 };
    std::cout << "Meeting length: " << meetingMinutes << " minutes\n";
    std::cout << "Workday length: " << workdayMinutes() << " minutes\n";
    return 0;
}
