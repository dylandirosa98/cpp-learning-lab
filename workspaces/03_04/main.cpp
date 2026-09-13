/*
Lesson 3.4 - Basic debugging tactics
LearnCpp: https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
What is practiced:
- Add temporary std::cerr traces to validate function flow and selected values,
  use the observations to repair production flow, and remove all diagnostics.
Explicit expected behavior:
- collectSectionCount executes once and supplies six sections.
- calculatePhotoCount executes once with six sections and three photos each.
- printReport executes once and reports six sections and 18 photos.
Debugging procedure:
1. Run the untouched starter and record its normal output.
2. Add a std::cerr entry message as the first statement of each helper.
3. Run again and compare call order and frequency with the behavior above.
4. If needed, trace sectionCount and photoCount to find the first divergence.
5. Repair the production call flow without changing the stated constants.
6. Remove every std::cerr statement and verify exact normal output.
File and function responsibilities:
- collectSectionCount supplies the deterministic section count.
- calculatePhotoCount computes photos from sections and photos per section.
- printReport owns both stdout lines.
- main stores results and coordinates the three helpers.
Constraints:
- Preserve all helper signatures and use each helper for its responsibility.
- Temporary diagnostics must use std::cerr, not std::cout.
- Remove all temporary diagnostics before running the final checker.
- Use explicit std:: qualification and no using namespace std.
Exact expected output:
Sections inspected: 6
Photos captured: 18
Completion checklist:
- Function-entry traces established the actual call sequence.
- Relevant stored values were observed rather than guessed.
- The production call flow now matches the required sequence.
- No std::cerr remains and the warning-free output matches exactly.
Run from project root: ./course check 3.4
*/
#include <iostream>

int collectSectionCount()
{
    return 6;
}

int calculatePhotoCount(int sections, int photosPerSection)
{
    return sections * photosPerSection;
}

void printReport(int sections, int photos)
{
    std::cout << "Sections inspected: " << sections << '\n';
    std::cout << "Photos captured: " << photos << '\n';
}

int main()
{
    int sectionCount{ collectSectionCount() };
    int photoCount{ calculatePhotoCount(sectionCount, 3) };

    printReport(sectionCount, photoCount);
    return 0;
}
