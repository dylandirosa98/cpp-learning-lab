#include <iostream>

void printGrade(int score)
{
    if (score >= 90)
    {
        std::cout << "Grade: A\n";
        std::cout << "Status: distinction\n";
    }
    else if (score >= 80)
    {
        std::cout << "Grade: B\n";
    }
    else
    {
        std::cout << "Grade: C or lower\n";
    }
}

int main()
{
    printGrade(95);
    printGrade(82);
    printGrade(60);
    return 0;
}
