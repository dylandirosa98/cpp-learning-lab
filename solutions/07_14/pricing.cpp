#include "pricing.h"

namespace
{
    constexpr int serviceFee{ 3 };
}

int Pricing::V1::total(int subtotal)
{
    return subtotal;
}

int Pricing::V2::total(int subtotal)
{
    return subtotal + serviceFee;
}
