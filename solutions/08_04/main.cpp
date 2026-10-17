#include <iostream>

constexpr bool debugBuild{ true };
constexpr bool verboseBuild{ false };

void printBuildReport()
{
    if constexpr (debugBuild)
    {
        std::cout << "Build: debug\n";
    }
    else
    {
        std::cout << "Build: release\n";
    }

    if constexpr (verboseBuild)
    {
        std::cout << "Verbose: yes\n";
    }
    else
    {
        std::cout << "Verbose: no\n";
    }
}

int main()
{
    printBuildReport();
    return 0;
}
