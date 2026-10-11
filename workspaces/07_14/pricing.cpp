/*
Lesson 7.14 - Unnamed and inline namespaces
LearnCpp: https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
Tasks:
- Hide a service-fee constant of 3 in this translation unit.
- Return the unchanged subtotal from V1 and subtotal plus fee from V2.
Namespace responsibilities:
- The unnamed namespace owns implementation detail unavailable to other files.
- Pricing::V1 and Pricing::V2 define the public versions declared in the header.
Expected behavior from the complete program:
- Legacy total is 20 and current total is 23 for a subtotal of 20.
Constraints:
- Include pricing.h first and perform no console input or output here.
- Do not expose the service fee in pricing.h or give it external linkage.
Completion checklist:
- The source-file-only fee is explicitly initialized inside an unnamed namespace.
- Each total implementation follows its version's stated behavior.
- The complete target builds warning-free and passes ./course check 7.14.
Run from project root: ./course check 7.14
*/
#include "pricing.h"

// TODO: Put a constexpr service fee of 3 in an unnamed namespace.
namespace {
constexpr int serviceFee{3};
}

int Pricing::V1::total(int subtotal) {
    return subtotal;
}

int Pricing::V2::total(int subtotal) {
    // TODO: Add the source-file-only service fee.
    return subtotal + serviceFee;
}
