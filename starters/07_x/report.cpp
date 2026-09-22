/*
Lesson 7.x - Chapter 7 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
Tasks:
- Implement every exact report line from values supplied by callers.
- Keep this module limited to formatting and console presentation.
Function responsibilities:
- printHeading writes the title and target count on separate lines.
- printSample writes one ID with its raw and calibrated readings.
- printSummary writes legacy, default, and average results in that order.
Expected behavior from the complete program:
- The report starts with "Field survey" and ends with average 42.
Constraints:
- Include report.h first; do not include survey.h or recalculate any value.
- Do not hard-code generated IDs, calibrated readings, or the average.
Completion checklist:
- Labels, punctuation, spacing, ordering, and newlines match metadata exactly.
- Each displayed number comes through the corresponding parameter.
- The complete target builds warning-free and passes ./course check 7.x.
Run from project root: ./course check 7.x
*/
#include "report.h"

#include <iostream>

namespace Report
{
    void printHeading(int targetSamples)
    {
        // TODO: Print the exact heading and target lines.
        std::cout << targetSamples << '\n';
    }

    void printSample(int id, int rawReading, int calibratedReading)
    {
        // TODO: Print one exact sample line using all three parameters.
        std::cout << id << ' ' << rawReading << ' ' << calibratedReading << '\n';
    }

    void printSummary(int legacyFirst, int defaultFirst, int average)
    {
        // TODO: Print the three exact summary lines in order.
        std::cout << legacyFirst << ' ' << defaultFirst << ' ' << average << '\n';
    }
}
