#include "roof_math.h"

int panelArea(int width, int height)
{
    return width * height;
}

int totalArea(int areaPerPanel, int panelCount)
{
    return areaPerPanel * panelCount;
}
