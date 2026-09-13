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
