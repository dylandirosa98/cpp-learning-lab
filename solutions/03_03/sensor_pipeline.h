#ifndef CPP_LEARNING_LAB_SENSOR_PIPELINE_H
#define CPP_LEARNING_LAB_SENSOR_PIPELINE_H

int normalizeReading(int rawReading, int offset);
int scaleReading(int reading, int factor);
int combineZones(int primary, int secondary);
int reserveCapacity(int combined, int holdback);

#endif
