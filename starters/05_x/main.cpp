/*
Lesson 5.x - Chapter 5 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-5-summary-and-quiz/
Tasks:
- Coordinate normal, reversed-argument, and deterministic tie checks without stdin.
- Name all fixed ages and text inputs with constexpr variables.
- Keep owning full names alive and unchanged while non-owning views refer to them.
Function responsibilities:
- main composes Ada Lovelace and Charles Babbage into const std::string owners.
- main requests age calculation and older-name selection from people.cpp.
- main passes only finished values to report.cpp in the required output order.
Expected output:
- Age comparison
- Person 1: Ada Lovelace (age 36)
- Person 2: Charles Babbage (age 79)
- Older person: Charles Babbage (age 79)
- Age difference: 43 years
- First-argument older check: Charles Babbage
- Tie rule: first person wins
- Tie selected: Ada Lovelace
Constraints:
- Do not include iostream, print directly, read stdin, or include .cpp files.
- Do not write composed full-name literals or hard-code the difference.
- Views must refer only to live string literals or the two live owning strings.
Completion checklist:
- Fixed values are named constexpr and composed names are const std::string.
- Second-older, first-older, and equal-age calls all use selectOlderName.
- The complete C++20 target is warning-clean and output matches exactly.
Run from project root: ./course check 5.x
*/
#include "people.h"
#include "report.h"

#include <string>
#include <string_view>

int main()
{
    constexpr std::string_view heading{ "Age comparison" };
    constexpr std::string_view adaFirstName{ "Ada" };
    constexpr std::string_view adaLastName{ "Lovelace" };
    constexpr int adaAge{ 36 };
    constexpr std::string_view charlesFirstName{ "Charles" };
    constexpr std::string_view charlesLastName{ "Babbage" };
    constexpr int charlesAge{ 79 };

    // TODO: Compose both owning names before selecting any views into them.
    const std::string adaName{ adaFirstName };
    const std::string charlesName{ charlesFirstName };
    const int difference{};
    const std::string_view olderName{ adaName };
    const std::string_view firstOlderName{ adaName };
    const std::string_view tieName{ charlesName };

    printHeading(heading);
    printPerson(1, adaName, adaAge);
    printPerson(2, charlesName, charlesAge);
    printOlderPerson(olderName, charlesAge);
    printAgeDifference(difference);
    printFirstOlderCheck(firstOlderName);
    printTieResult(tieName);

    return 0;
}
