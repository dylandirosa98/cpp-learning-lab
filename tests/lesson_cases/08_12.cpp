#define main learner_main
#include "main.cpp"
#undef main
#include <cstdlib>
#include <iostream>
int main(int argc, char** argv)
{
    if (argc != 2) return 98;
    exitForStatus(std::atoi(argv[1]));
    std::cerr << "exitForStatus returned instead of terminating the process\n";
    return 99;
}
