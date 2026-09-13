#include <iostream>

int roofLoad(int panels, int kilogramsPerPanel);

int main()
{
    std::cout << "Calculated roof load: " << roofLoad(12, 12) << " kg\n";
    return 0;
}

int roofLoad(int panels, int kilogramsPerPanel)
{
    return panels * kilogramsPerPanel;
}
