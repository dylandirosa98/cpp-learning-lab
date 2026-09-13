/*
Lesson 3.3 - A strategy for debugging
LearnCpp: https://www.learncpp.com/cpp-tutorial/a-strategy-for-debugging/
What is practiced:
- Use reproducible inputs and debugger checkpoints to discard correct regions
  of a multi-stage calculation before making a focused repair.
Explicit expected behavior:
- normalizeReading receives 18 and 2 and returns 20.
- scaleReading receives 20 and 3 and returns 60.
- combineZones receives 60 and 12 and returns 72.
- reserveCapacity receives 72 and 7 and returns 65.
Debugging procedure:
1. Run the unmodified program once and retain the observed values.
2. Break after the midpoint combineZones() call in main.
3. If combined differs from 72, inspect scaled and normalized in reverse order.
4. Stop where a function receives the expected inputs but returns a bad value.
5. Step through that function to understand its operation before editing.
6. Make one repair and retest all four stages through final output.
File and function responsibilities:
- This file includes sensor_pipeline.h first and defines all four stages.
- Each function transforms only its parameters and returns one int result.
- This module performs no console output.
- main.cpp coordinates the stages and owns presentation.
Constraints:
- Keep all signatures and stage responsibilities unchanged.
- Use whole-number arithmetic and fixed deterministic inputs.
- Do not add output or using namespace std to this module.
Exact expected output:
Normalized reading: 20
Combined load: 72
Available capacity: 65
Completion checklist:
- The midpoint observation determined which direction to investigate.
- The first incorrect stage is supported by inspected runtime values.
- Only that stage was repaired and all later values now follow correctly.
- The complete program compiles warning-free and output matches exactly.
Run from project root: ./course check 3.3
*/
#include "sensor_pipeline.h"

int normalizeReading(int rawReading, int offset)
{
    return rawReading + offset;
}

int scaleReading(int reading, int factor)
{
    return reading + factor;
}

int combineZones(int primary, int secondary)
{
    return primary + secondary;
}

int reserveCapacity(int combined, int holdback)
{
    return combined - holdback;
}
