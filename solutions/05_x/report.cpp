#include "report.h"

#include <iostream>

void printHeading(std::string_view heading)
{
    std::cout << heading << '\n';
}

void printPerson(int number, std::string_view name, int age)
{
    std::cout << "Person " << number << ": " << name << " (age " << age << ")\n";
}

void printOlderPerson(std::string_view name, int age)
{
    std::cout << "Older person: " << name << " (age " << age << ")\n";
}

void printAgeDifference(int difference)
{
    std::cout << "Age difference: " << difference << " years\n";
}

void printFirstOlderCheck(std::string_view name)
{
    std::cout << "First-argument older check: " << name << '\n';
}

void printTieResult(std::string_view name)
{
    std::cout << "Tie rule: first person wins\n";
    std::cout << "Tie selected: " << name << '\n';
}
