#include "time_constants.h"

int workdayMinutes()
{
    return timeConstants::hoursPerWorkday * timeConstants::minutesPerHour;
}
