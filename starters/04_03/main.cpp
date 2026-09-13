/*
Lesson 4.3 - Object sizes and the sizeof operator
LearnCpp: https://www.learncpp.com/cpp-tutorial/object-sizes-and-the-sizeof-operator/
What is practiced:
- Query object-type sizes in C++ bytes with sizeof.
- State only guarantees that remain true across conforming implementations.
Required repair:
1. Predict each supplied false result before changing an operator.
2. Make the char claim test equality with the guaranteed byte count.
3. Reverse the three integer-size comparisons while preserving operand order.
4. Use comparisons that permit adjacent integer types to have equal sizes.
Portable facts:
- sizeof(char) is exactly 1 C++ byte.
- short is no larger than int, int no larger than long, and long no larger
  than long long.
File responsibilities:
- main evaluates and presents four portable type-size relationships.
Constraints:
- Keep every sizeof type operand and derive each bool from a comparison.
- Do not replace a relationship with a literal true or numeric desktop size.
- Do not apply sizeof to void, use input, or import the std namespace.
Exact expected output:
char is one byte: true
short no larger than int: true
int no larger than long: true
long no larger than long long: true
Completion checklist:
- No claim assumes int is four bytes or long is eight bytes.
- Equality is allowed in each relative integer-size relationship.
- The C++20 build is warning-free and all four lines match exactly.
Run from project root: ./course check 4.3
*/
#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    std::cout << "char is one byte: " << (sizeof(char) != 1) << '\n';
    std::cout << "short no larger than int: " << (sizeof(short) > sizeof(int)) << '\n';
    std::cout << "int no larger than long: " << (sizeof(int) > sizeof(long)) << '\n';
    std::cout << "long no larger than long long: " << (sizeof(long) > sizeof(long long)) << '\n';
    return 0;
}
