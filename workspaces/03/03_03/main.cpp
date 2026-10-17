/*
Lesson 3.3 - A strategy for debugging
LearnCpp: https://www.learncpp.com/cpp-tutorial/a-strategy-for-debugging/
What is practiced:
- Reproduce a fixed failure and use a high-low checkpoint strategy to isolate
  one incorrect stage without reading or changing every line first.
Explicit expected behavior:
- Normalizing raw 18 with offset 2 produces 20.
- Scaling by 3 then combining 12 produces a combined load of 72.
- A holdback of 7 leaves available capacity of 65.
Debugging procedure:
1. Run this untouched pipeline and record all three displayed values.
2. Set a breakpoint after combineZones() and inspect combined.
3. If it is not 72, inspect normalized and scaled; otherwise inspect available.
4. Continue until adjacent checkpoints bound the first incorrect transition.
5. Step into that stage, inspect its parameters and return value, then explain
   the disagreement before editing.
6. Repair one stage and rerun the entire fixed-input pipeline.
File and function responsibilities:
- main supplies fixed inputs, calls stages in order, and owns output.
- sensor_pipeline.h declares the four operations used here.
- sensor_pipeline.cpp owns calculations and performs no output.
Constraints:
- Preserve calls, stored stage variables, fixed values, and output labels.
- Do not hard-code the expected numeric results into output strings.
- Include the header rather than a .cpp file.
- Use explicit std:: qualification and no using namespace std.
Exact expected output:
Normalized reading: 20
Combined load: 72
Available capacity: 65
Completion checklist:
- Baseline output was captured before editing.
- Midpoint and neighboring state were inspected in the debugger.
- Exactly one isolated stage was repaired.
- The final warning-free run prints the exact expected lines.
Run from project root: ./course check 3.3
*/
#include "sensor_pipeline.h"

#include <iostream>

int main()
{
    int normalized{ normalizeReading(18, 2) };
    int scaled{ scaleReading(normalized, 3) };
    int combined{ combineZones(scaled, 12) };
    int available{ reserveCapacity(combined, 7) };

    std::cout << "Normalized reading: " << normalized << '\n';
    std::cout << "Combined load: " << combined << '\n';
    std::cout << "Available capacity: " << available << '\n';
    return 0;
}
