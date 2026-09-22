#include "config.h"
#include "report.h"
#include "survey.h"

int main()
{
    using Survey::calibrate;

    const int firstId{ Survey::nextSampleId() };
    const int secondId{ Survey::nextSampleId() };
    const int thirdId{ Survey::nextSampleId() };

    const int firstCalibrated{ calibrate(SurveyConfig::firstReading) };
    const int secondCalibrated{ calibrate(SurveyConfig::secondReading) };
    const int thirdCalibrated{ calibrate(SurveyConfig::thirdReading) };
    const int average{ (firstCalibrated + secondCalibrated + thirdCalibrated) / SurveyConfig::targetSamples };

    Report::printHeading(SurveyConfig::targetSamples);
    Report::printSample(firstId, SurveyConfig::firstReading, firstCalibrated);
    Report::printSample(secondId, SurveyConfig::secondReading, secondCalibrated);
    Report::printSample(thirdId, SurveyConfig::thirdReading, thirdCalibrated);
    Report::printSummary(
        Survey::V1::calibrate(SurveyConfig::firstReading), firstCalibrated, average);
    return 0;
}
