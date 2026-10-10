/*
Lesson 7.11 - Static local variables
LearnCpp: https://www.learncpp.com/cpp-tutorial/static-local-variables/
Practice:
- Preserve private function state across repeated calls.
- Distinguish a local name's block scope from its object's static duration.
Tasks:
1. Change the ticket counter to an explicitly initialized static unsigned int.
2. Return the current ticket and then increment the stored counter.
3. Keep the three deterministic calls and exact output formatting.
Function responsibilities:
- issueTicket owns and advances the one program-wide ticket sequence.
- main requests three tickets and prints them without duplicating counter logic.
Constraints:
- Keep the counter inside issueTicket; do not introduce a global variable.
- Do not hard-code individual ticket results or read stdin.
Exact expected output:
Ticket: 100
Ticket: 101
Ticket: 102
Completion checklist:
- The counter has block scope, static duration, and an explicit initial value.
- Consecutive calls return 100, 101, and 102.
- The C++20 target builds warning-free and output matches exactly.
Run from project root: ./course check 7.11
*/
#include <iostream>

unsigned int issueTicket() {
    // TODO: Give this local static duration and advance it after selecting the result.
    static unsigned int s_nextTicket{100};
    return s_nextTicket++;
}

int main() {
    std::cout << "Ticket: " << issueTicket() << '\n';
    std::cout << "Ticket: " << issueTicket() << '\n';
    std::cout << "Ticket: " << issueTicket() << '\n';
    return 0;
}
