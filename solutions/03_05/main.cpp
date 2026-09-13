#include "inspection_alert.h"

#include <iostream>

int main()
{
    int alertScore{ calculateAlertScore(2, 1) };
    int responseMinutes{ calculateResponseMinutes(alertScore, 4) };

    std::cout << "System alert score: " << alertScore << '\n';
    std::cout << "Response window: " << responseMinutes << " minutes\n";
    return 0;
}
