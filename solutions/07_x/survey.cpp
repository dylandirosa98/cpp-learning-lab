#include "survey.h"

namespace
{
    constexpr int calibrationOffset{ 2 };
}

namespace Survey
{
    extern const int g_firstSampleId{ 100 };

    int nextSampleId()
    {
        static int s_nextSampleId{ g_firstSampleId };
        return s_nextSampleId++;
    }

    int V1::calibrate(int rawReading)
    {
        return rawReading;
    }

    int V2::calibrate(int rawReading)
    {
        return rawReading + calibrationOffset;
    }
}
