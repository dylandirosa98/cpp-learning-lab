#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    for (int code{-20}; code <= 20; ++code)
    {
        const std::string_view expected{code == 1 ? "running" : code == 2 ? "paused" : code == 3 ? "stopped" : "unknown"};
        checkEqual(statusMessage(code), expected, "statusMessage: valid and unknown codes");
    }
    return 0;
}
