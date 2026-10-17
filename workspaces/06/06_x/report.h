/*
Lesson 6.x - Chapter 6 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-6-summary-and-quiz/
Tasks:
- Declare the complete presentation interface used by main.
- Accept descriptions as inexpensive read-only std::string_view values.
Function responsibilities:
- printHeading writes the fixed report heading.
- printQuantity formats a supplied description and quantity with its apple label.
- printStatus selects wording from an already-calculated boolean decision.
- printCrates reports an already-calculated crate count.
Expected output from the complete program:
- Ten exact lines describe 24 started, 7 sold, 2 spoiled, 15 remaining,
  restocking 5 via 2 crates, projected 23, and singular "1 apple".
Constraints:
- Keep this header declaration-only, include-guarded, and free of stream output.
- Do not declare inventory arithmetic here or import namespace std.
Completion checklist:
- Signatures match report.cpp and every declaration is inside the guard.
- Quantity descriptions remain caller-supplied string views.
- The complete target builds warning-free and passes ./course check 6.x.
Run from project root: ./course check 6.x
*/
#ifndef CPP_LEARNING_LAB_CHAPTER6_REPORT_H
#define CPP_LEARNING_LAB_CHAPTER6_REPORT_H

#include <string_view>

void printHeading();
void printQuantity(std::string_view description, int quantity);
void printStatus(bool restockRequired);
void printCrates(int crates);

#endif
