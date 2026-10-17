/*
Lesson 8.5 - Switch statement basics
LearnCpp: https://www.learncpp.com/cpp-tutorial/switch-statement-basics/

Problem:
Implement statusMessage using a switch statement. Return "running" for 1, "paused" for 2, "stopped" for 3, and "unknown" for every other integer. Return the text; do not print it.

Expected results (examples):
- statusMessage(1) -> "running"
- statusMessage(2) -> "paused"
- statusMessage(3) -> "stopped"
- statusMessage(0) -> "unknown"
- statusMessage(-7) -> "unknown"

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.5
*/
#include <iostream>
#include <string_view>


std::string_view statusMessage(int statusCode)
{
    switch (statusCode)
    {
        case 1: return "running";
        case 2: return "paused";
        case 3: return "stopped";
        default: return "unknown";
    }
}

int main()
{
    return 0;
}
