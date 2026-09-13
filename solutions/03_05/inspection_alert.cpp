#include "inspection_alert.h"

#include "diagnostics.h"

int calculateAlertScore(int waterEvents, int electricalEvents)
{
    LAB_LOG("calculateAlertScore inputs: water=" << waterEvents
                                                  << ", electrical=" << electricalEvents);
    int alertScore{ waterEvents * 3 + electricalEvents * 5 };
    LAB_LOG("calculateAlertScore result: " << alertScore);
    return alertScore;
}

int calculateResponseMinutes(int alertScore, int minutesPerPoint)
{
    LAB_LOG("calculateResponseMinutes inputs: score=" << alertScore
                                                       << ", minutesPerPoint=" << minutesPerPoint);
    int responseMinutes{ alertScore * minutesPerPoint };
    LAB_LOG("calculateResponseMinutes result: " << responseMinutes);
    return responseMinutes;
}
