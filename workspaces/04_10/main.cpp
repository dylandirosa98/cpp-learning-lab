/*
Lesson 4.10 - Introduction to if statements
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
Practice:
- Select exactly one behavior with an if, else-if, else chain.
- Align each comparison with the state described by its output.
Task:
1. Keep printTemperatureState and all three calls.
2. Make the first branch handle temperatures below zero.
3. Make the second branch handle temperatures above zero.
4. Let the final else handle exactly zero.
5. Preserve the shared numeric prefix printed before the chain.
Function responsibility:
- printTemperatureState classifies and prints one supplied temperature.
- main invokes all three paths in the required order.
Constraints:
- Use one if/else-if/else chain; do not hard-code complete report lines.
- Do not add input or change the test temperatures.
Exact expected output:
Temperature -4: below freezing
Temperature 0: freezing point
Temperature 7: above freezing
Completion checklist:
- Negative, zero, and positive values reach different correct branches.
- Exactly one line is produced per call.
- The program builds warning-free as C++20.
Run from project root: ./course check 4.10
*/
#include <iostream>

void printTemperatureState(int temperature) {
    std::cout << "Temperature " << temperature << ": ";
    if (temperature < 0)
        std::cout << "below freezing\n";
    else if (temperature == 0)
        std::cout << "freezing point\n";
    else
        std::cout << "above freezing\n";
}

int main() {
    printTemperatureState(-4);
    printTemperatureState(0);
    printTemperatureState(7);
    return 0;
}
