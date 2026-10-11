/*
Lesson 7.14 - Unnamed and inline namespaces
LearnCpp: https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
Tasks:
- Declare legacy Pricing::V1 and current Pricing::V2 total functions.
- Make V2 the inline namespace so its API is the Pricing default.
Namespace responsibilities:
- V1 preserves legacy behavior that returns a subtotal unchanged.
- V2 exposes current behavior both as Pricing::V2::total and Pricing::total.
Expected behavior from the complete program:
- A subtotal of 20 is 20 in V1 and 23 through both current API names.
Constraints:
- Keep this header declaration-only and free of unnamed namespaces.
- Protect every declaration with the unique include guard.
Completion checklist:
- V1 is a normal namespace and V2 is explicitly inline.
- Both versions declare the same total(int) interface.
- The complete target builds warning-free and passes ./course check 7.14.
Run from project root: ./course check 7.14
*/
#ifndef CPP_LEARNING_LAB_CHAPTER7_PRICING_H
#define CPP_LEARNING_LAB_CHAPTER7_PRICING_H

namespace Pricing {
namespace V1 {
int total(int subtotal);
}

// TODO: Make V2 the inline namespace selected through Pricing::total.
inline namespace V2 {
int total(int subtotal);
}
} // namespace Pricing

#endif
