/*
Lesson 7.6 - Internal linkage
LearnCpp: https://www.learncpp.com/cpp-tutorial/internal-linkage/
Tasks:
- Define a namespace-scope static int g_offset initialized to 5.
- Give applyOffset internal linkage and have it add this file's offset.
- Keep sensorReading externally linked and delegate its result to applyOffset.
Concept:
- Internal names are usable throughout this translation unit but cannot link from main.cpp.
Expected behavior:
- sensorReading(10) returns 15 by applying this file's offset.
Constraints:
- Do not use extern for either internal identifier or include another .cpp file.
Completion checklist:
- Both g_offset and applyOffset are static; sensorReading is not static.
- The complete target passes ./course check 7.6.
*/
static int g_offset{5}; // TODO: Initialize this internal variable correctly.

static int applyOffset(int reading) {
    return reading + g_offset; // TODO: Apply g_offset in the correct direction.
}

int sensorReading(int reading) {
    return applyOffset(reading);
}
