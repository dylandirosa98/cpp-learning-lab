#include "people.h"

std::string composeFullName(std::string_view firstName, std::string_view lastName)
{
    std::string fullName{ firstName };
    fullName += ' ';
    fullName += lastName;
    return fullName;
}

int ageDifference(int firstAge, int secondAge)
{
    if (firstAge >= secondAge)
        return firstAge - secondAge;

    return secondAge - firstAge;
}

std::string_view selectOlderName(std::string_view firstName, int firstAge, std::string_view secondName, int secondAge)
{
    if (firstAge >= secondAge)
        return firstName;

    return secondName;
}
