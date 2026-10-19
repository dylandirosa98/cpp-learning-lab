#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for (bool express : {false, true}) {
        for (int weight : {-5, 0, 1, 4, 5, 6, 19, 20, 21, 100}) {
            const int expected{weight <= 0 ? -1 : (weight <= 5 ? 5 : weight <= 20 ? 10 : 20) + (express ? 7 : 0)};
            Lab::eq(shippingFee(weight, express), expected, "weight=" + std::to_string(weight) + ", express=" + std::to_string(express));
        }
    }
    return Lab::finish();
}
