/*
Lesson 7.7 - External linkage and variable forward declarations
LearnCpp: https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/
Tasks:
- Define non-const g_dailyLimit as 12; it has external linkage by default.
- Define const g_bonusLimit as 3 and use extern to give it external linkage.
Concept:
- These are the program's single definitions, while main.cpp contains declarations.
Expected behavior:
- The definitions provide 12 and 3 so main.cpp calculates a capacity of 15.
Constraints:
- Do not put extern on the initialized non-const definition.
Completion checklist:
- Types, names, constness, and values match main.cpp's declarations.
- The complete target passes ./course check 7.7 without warnings.
*/
int g_dailyLimit{12};             // TODO: Initialize the externally linked non-const definition.
extern const int g_bonusLimit{3}; // TODO: Initialize this external const definition to 3.
