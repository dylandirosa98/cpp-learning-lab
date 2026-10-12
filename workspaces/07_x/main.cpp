/*
Lesson 7.x - Chapter 7 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
Tasks:
- Introduce only Survey::calibrate with a block-scoped using-declaration.
- Request three generated IDs and calibrate all configured readings.
- Calculate the integer average and coordinate the complete report.
Function responsibilities:
- main owns automatic result lifetimes and calls modules in dependency order.
- Survey calculates identities/calibration; Report alone performs output.
Expected output:
- Field survey; target 3; IDs 100-102 with calibrated values 42, 45, 40.
- Legacy first 40; default first 42; average calibrated 42.
Constraints:
- Do not include iostream, read stdin, use a namespace directive, or hard-code results.
- Keep the using-declaration inside main and all report calls explicitly qualified.
Completion checklist:
- IDs, calibrated readings, and average are named const automatic locals.
- V1 is selected explicitly only for the legacy result; V2 is the default.
- The complete C++20 target is warning-clean and output matches exactly.
Run from project root: ./course check 7.x
*/
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
    Report::printSummary(Survey::V1::calibrate(SurveyConfig::firstReading), firstCalibrated, average);
    return 0;
}
