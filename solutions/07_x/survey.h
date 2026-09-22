#ifndef CPP_LEARNING_LAB_CHAPTER7_SURVEY_H
#define CPP_LEARNING_LAB_CHAPTER7_SURVEY_H

namespace Survey
{
    extern const int g_firstSampleId;

    int nextSampleId();

    namespace V1
    {
        int calibrate(int rawReading);
    }

    inline namespace V2
    {
        int calibrate(int rawReading);
    }
}

#endif
