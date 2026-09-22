#include "counter.h"

extern const int g_dailyLimit{ 3 };

int visitsToday()
{
    static int s_visits{ 0 };
    ++s_visits;
    return s_visits;
}
