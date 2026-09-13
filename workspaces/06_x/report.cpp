/*
Lesson 6.x - Chapter 6 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-6-summary-and-quiz/
Tasks:
- Format the heading, quantity, status, and crate lines from supplied values.
- Ask appleLabel for singular/plural wording instead of duplicating that rule.
Function responsibilities:
- printHeading prints exactly "Apple inventory" and one newline.
- printQuantity prints "description: quantity label" and one newline.
- printStatus uses its boolean only to choose the required status wording.
- printCrates prints the supplied crate count with its exact label.
Expected output from the complete program:
- The report has ten lines and ends with "Pluralization check: 1 apple".
- Labels, capitalization, spacing, ordering, and newlines match the lesson metadata.
Constraints:
- Include report.h first; only this source file may include iostream or use cout.
- Do not calculate inventory counts, hard-code results, or read stdin.
Completion checklist:
- Every numeric result comes through a parameter and quantity lines call appleLabel.
- Status selection uses the conditional operator with the supplied bool.
- The complete target builds warning-free and passes ./course check 6.x.
Run from project root: ./course check 6.x
*/
#include "report.h"

#include "inventory.h"

#include <iostream>

void printHeading()
{
    std::cout << "Apple inventory\n";
}

void printQuantity(std::string_view description, int quantity)
{
    // TODO: Print the description, quantity, and appleLabel(quantity).
    std::cout << description << quantity << '\n';
}

void printStatus(bool restockRequired)
{
    // TODO: Select "restock required" or "stock level healthy".
    std::cout << "Status: " << restockRequired << '\n';
}

void printCrates(int crates)
{
    // TODO: Print the exact crate-order line from the supplied count.
    std::cout << crates << '\n';
}
