#include <iostream>

int calculateTotalDefects(int flashingDefects, int fastenerDefects)
{
    return flashingDefects + fastenerDefects;
}

int calculateRepairMinutes(int defects, int minutesPerDefect)
{
    return defects * minutesPerDefect;
}

void printWorkOrder(int defects, int repairMinutes)
{
    std::cout << "Defects logged: " << defects << '\n';
    std::cout << "Estimated repair time: " << repairMinutes << " minutes\n";
}

int main()
{
    int defects{ calculateTotalDefects(3, 5) };
    int repairMinutes{ calculateRepairMinutes(defects, 12) };
    printWorkOrder(defects, repairMinutes);
    return 0;
}
