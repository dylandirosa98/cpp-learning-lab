#ifndef CPP_LEARNING_LAB_CHAPTER5_PEOPLE_H
#define CPP_LEARNING_LAB_CHAPTER5_PEOPLE_H

#include <string>
#include <string_view>

std::string composeFullName(std::string_view firstName, std::string_view lastName);
int ageDifference(int firstAge, int secondAge);
std::string_view selectOlderName(std::string_view firstName, int firstAge, std::string_view secondName, int secondAge);

#endif
