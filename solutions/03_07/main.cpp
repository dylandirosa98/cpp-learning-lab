#include <iostream>

int recordStage(int elapsed, int stageMinutes)
{
    return elapsed + stageMinutes;
}

int main()
{
    int elapsed{};
    elapsed = recordStage(elapsed, 14);
    elapsed = recordStage(elapsed, 9);
    elapsed = recordStage(elapsed, 7);

    std::cout << "Loading timeline: " << elapsed << " minutes\n";
    return 0;
}
