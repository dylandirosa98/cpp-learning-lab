/*
Lesson 7.x - Chapter 7 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
Tasks:
- Define the fixed sample target and three raw readings in SurveyConfig.
- Make each header-defined constant an inline constexpr int.
Module responsibilities:
- config.h owns immutable scenario configuration shared by other files.
- It declares no functions, mutable state, external object, or output behavior.
Expected behavior from the complete program:
- Three readings 40, 43, and 38 are calibrated and reported deterministically.
Constraints:
- Keep this header-only module protected by the unique include guard.
- Do not use extern declarations, streams, or namespace directives here.
Completion checklist:
- All four constants are inline constexpr int values in SurveyConfig.
- The target is 3 and the readings appear in their required order.
- The complete target builds warning-free and passes ./course check 7.x.
Run from project root: ./course check 7.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER7_CONFIG_H
#define CPP_LEARNING_LAB_CHAPTER7_CONFIG_H

namespace SurveyConfig
{
    // TODO: Add inline to each shared header constant and correct each value.
    constexpr int targetSamples{ 1 };
    constexpr int firstReading{ 0 };
    constexpr int secondReading{ 0 };
    constexpr int thirdReading{ 0 };
}

#endif
