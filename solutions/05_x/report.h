#ifndef CPP_LEARNING_LAB_CHAPTER5_REPORT_H
#define CPP_LEARNING_LAB_CHAPTER5_REPORT_H

#include <string_view>

void printHeading(std::string_view heading);
void printPerson(int number, std::string_view name, int age);
void printOlderPerson(std::string_view name, int age);
void printAgeDifference(int difference);
void printFirstOlderCheck(std::string_view name);
void printTieResult(std::string_view name);

#endif
