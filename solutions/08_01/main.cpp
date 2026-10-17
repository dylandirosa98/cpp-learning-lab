#include <iostream>

void printScoreResult(int score, int passMark)
{
    std::cout << "Score " << score << ": ";
    if (score >= passMark)
    {
        std::cout << "pass\n";
    }
    else
    {
        std::cout << "fail\n";
    }
}

int main()
{
    printScoreResult(72, 60);
    printScoreResult(45, 60);
    return 0;
}
