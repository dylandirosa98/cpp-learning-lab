#include <iostream>

int main()
{
    const int rows{ 4 };
    constexpr int seatsPerRow{ 6 };
    constexpr int capacity{ rows * seatsPerRow };
    static_assert(capacity == 24);

    std::cout << "Capacity: " << capacity << " seats\n";
    return 0;
}
