static int g_offset{ 5 };

static int applyOffset(int reading)
{
    return reading + g_offset;
}

int sensorReading(int reading)
{
    return applyOffset(reading);
}
