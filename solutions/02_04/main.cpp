#include <iostream>

int panelLoad(int panelCount, int kilogramsPerPanel)
{
    return panelCount * kilogramsPerPanel;
}

int addToolLoad(int materialLoad, int toolLoad)
{
    return materialLoad + toolLoad;
}

int main()
{
    int materialLoad{panelLoad(12, 18)};
    int loadedTotal{addToolLoad(materialLoad, 24)};

    std::cout << "Material load: " << materialLoad << " kg\n";
    std::cout << "Loaded system total: " << loadedTotal << " kg\n";

    return 0;
}
