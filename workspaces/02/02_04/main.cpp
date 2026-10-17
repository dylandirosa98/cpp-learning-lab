/*
Lesson 2.4: Introduction to function parameters and arguments
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/

What you are practicing:
- Receiving caller-provided values through typed parameters.
- Calculating and returning a result from more than one parameter.
- Passing one function's returned result into another function call.

Before coding:
- In a definition, panelCount and kilogramsPerPanel are parameters. In the
  call panelLoad(12, 18), 12 and 18 are arguments.
- main() already makes the required calls and prints their stored results.
- Only replace the two TODOs and their placeholder return statements.

Exact numbered instructions for every function:
1. panelLoad(): Multiply panelCount by kilogramsPerPanel and return the result.
2. addToolLoad(): Add materialLoad and toolLoad and return the result.
3. main(): Keep the load for 12 panels at 18 kg each stored in materialLoad,
   pass materialLoad and 24 to addToolLoad(), store the returned total, print
   both existing labeled lines, and return success.

Language-neutral pseudocode for each TODO:
- panelLoad TODO:
  SET material load to panel count multiplied by kilograms per panel
  RETURN material load
- addToolLoad TODO:
  SET loaded total to material load plus tool load
  RETURN loaded total

Input/output examples:
- panelLoad with 12 and 18 returns 216.
- panelLoad with 5 and 10 returns 50.
- addToolLoad with 216 and 24 returns 240.

Constraints:
- Keep both function names, int return types, and parameter lists unchanged.
- Use both named parameters in each function's calculation.
- Do not hard-code 216 or 240 in an output string.
- Use std::cout for output. Do not use unqualified cout.
- Do not add using namespace std or a using declaration for cout.

Exact expected output:
Material load: 216 kg
Loaded system total: 240 kg

Completion checklist:
- [ ] Both placeholder returns are replaced with parameter-based calculations.
- [ ] main() passes materialLoad into addToolLoad().
- [ ] The labels, calculated values, units, and line breaks match exactly.
- [ ] No function signature was changed.

Checker command:
./course check 2.4
*/

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


int doubleNumber(int x)
{
    return 2 * x;
}

void readIntFromUser()
{
    int x{};
    std::cin >> x;
    std::cout << doubleNumber(x);
}