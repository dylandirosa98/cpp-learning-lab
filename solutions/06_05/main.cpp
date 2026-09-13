#include <iostream>

int main()
{
    int auditCode{ 4 };
    int auditResult{ (auditCode += 2, auditCode * 3) };

    std::cout << "Audit code after left operand: " << auditCode << '\n';
    std::cout << "Comma expression result: " << auditResult << '\n';
    return 0;
}
