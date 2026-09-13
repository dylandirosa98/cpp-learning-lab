#include <iostream>

#define ROOF_DIAGNOSTICS

int main()
{
    std::cout << "Inspection status: ready\n";

#ifdef ROOF_DIAGNOSTICS
    std::cout << "Diagnostics: sensor bus online\n";
#endif

#ifdef LEGACY_SENSOR
    std::cout << "Diagnostics: legacy sensor enabled\n";
#endif

    return 0;
}
