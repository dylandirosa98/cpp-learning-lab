/*
Lesson 7.10 - Sharing global constants across multiple files (using inline variables)
LearnCpp: https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
Tasks:
- Include time_constants.h and forward declare workdayMinutes from schedule.cpp.
- Calculate a constexpr 90-minute meeting using minutesPerHour plus half an hour.
- Print the meeting and workday lengths.
Constraints:
- Do not repeat constant definitions, use raw result literals, or include schedule.cpp.
Exact expected output:
Meeting length: 90 minutes
Workday length: 480 minutes
Completion checklist:
- meetingMinutes is a constant expression using the shared namespaced constant.
- The C++20 target builds warning-free and passes ./course check 7.10.
*/
#include "time_constants.h"

#include <iostream>

int workdayMinutes();

int main()
{
    constexpr int meetingMinutes{ 0 }; // TODO: Add one hour and half an hour.
    std::cout << "Meeting length: " << meetingMinutes << " minutes\n";
    std::cout << "Workday length: " << workdayMinutes() << " minutes\n";
    return 0;
}
