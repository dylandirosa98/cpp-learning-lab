/*
Lesson 4.11 - Chars
LearnCpp: https://www.learncpp.com/cpp-tutorial/chars/
Practice:
- Store one marker in a char and print it with character punctuation.
- Use quote, backslash, tab, and newline escape sequences correctly.
Task:
1. Keep marker initialized with the single character literal 'K'.
2. Change its surrounding output punctuation from double quotes to single quotes.
3. Keep the path's escaped backslashes so two literal separators appear.
4. Repair the columns line to print A, one tab, then B.
5. End all three lines with a newline escape.
Constraints:
- Do not use numeric character codes or multicharacter literals.
- Keep the path in source as C:\\lab\\chapter4 using escaped backslashes.
Exact expected output:
Marker: 'K'
Path: C:\lab\chapter4
Columns: A	B
Completion checklist:
- marker remains a char, not a string or integer.
- Quotes, path separators, tab, and newlines render exactly.
- The program builds warning-free as C++20.
Run from project root: ./course check 4.11
*/
#include <iostream>

int main() {
    char marker{'K'};
    std::cout << "Marker: \'" << marker << "\'" << '\n';
    std::cout << "Path: C:\\lab\\chapter4" << '\n';
    std::cout << "Columns: A" << '\t' << 'B' << '\n';
    return 0;
}
