#include <iostream>
#include <string> // for std::uint8_t
/*
 * Enter the name of person #1: John Bacon
Enter the age of John Bacon: 37
Enter the name of person #2: David Jenkins
Enter the age of David Jenkins: 44
David Jenkins (age 44) is older than John Bacon (age 37).
*/
int main() {
    std::cout << "Enter the name of person #1: ";
    std::string person1{};
    getline(std::cin >> std::ws, person1);

    int age1{};
    std::cout << "Enter the age of " << person1 << ": ";
    std::cin >> age1;
    std::cout << "Enter the name of person #2: ";
    std::string person2{};
    getline(std::cin >> std::ws, person2);

    int age2{};
    std::cout << "Enter the age of " << person2 << ": ";
    std::cin >> age2;

    std::string_view oldername{};
    std::string_view youngername{};

    if (age1 > age2) {
        oldername = person1;
        youngername = person2;
    } else {
        oldername = person2;
        youngername = person1;
    }

    std::cout << oldername << " (age " << (age1 > age2 ? age1 : age2) << ") is older than "
              << youngername << " (age " << (age1 > age2 ? age2 : age1) << ").\n";
    return 0;
}
