#ifndef CPP_LEARNING_LAB_CHAPTER7_REPORT_H
#define CPP_LEARNING_LAB_CHAPTER7_REPORT_H

namespace Report
{
    void printHeading(int targetSamples);
    void printSample(int id, int rawReading, int calibratedReading);
    void printSummary(int legacyFirst, int defaultFirst, int average);
}

#endif
