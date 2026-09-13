#include "sensor_pipeline.h"

int normalizeReading(int rawReading, int offset)
{
    return rawReading + offset;
}

int scaleReading(int reading, int factor)
{
    return reading * factor;
}

int combineZones(int primary, int secondary)
{
    return primary + secondary;
}

int reserveCapacity(int combined, int holdback)
{
    return combined - holdback;
}
