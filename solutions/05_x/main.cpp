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

    const std::string adaName{ composeFullName(adaFirstName, adaLastName) };
    const std::string charlesName{ composeFullName(charlesFirstName, charlesLastName) };
    const int difference{ ageDifference(adaAge, charlesAge) };
    const std::string_view olderName{ selectOlderName(adaName, adaAge, charlesName, charlesAge) };
    const std::string_view firstOlderName{ selectOlderName(charlesName, charlesAge, adaName, adaAge) };
    const std::string_view tieName{ selectOlderName(adaName, adaAge, charlesName, adaAge) };

    printHeading(heading);
    printPerson(1, adaName, adaAge);
    printPerson(2, charlesName, charlesAge);
    printOlderPerson(olderName, charlesAge);
    printAgeDifference(difference);
    printFirstOlderCheck(firstOlderName);
    printTieResult(tieName);

    return 0;
}
