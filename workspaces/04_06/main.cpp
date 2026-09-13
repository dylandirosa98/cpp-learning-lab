/*
Lesson 4.6 - Fixed-width integers and size_t
LearnCpp: https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
What is practiced:
- Use std::int32_t where an exact 32-bit signed range is required.
- Store sizeof results and byte counts in std::size_t.
Required repair:
1. Preserve the <cstdint> and <cstddef> headers and all declared types.
2. Calculate packetDelta in the stated received-minus-sent direction.
3. Treat fieldBytes as the byte size of one fixed-width field.
4. Calculate payloadBytes for fieldCount equally sized fields.
Calculation contract:
- received is 48,000, sent is 49,200, and fieldCount is 3.
- fieldBytes comes from sizeof; no particular implementation byte size is
  assumed by the output contract.
Object responsibilities:
- std::int32_t objects hold packet quantities requiring the guaranteed range.
- std::size_t objects hold byte sizes and the field count used with them.
Constraints:
- Keep all object names, fixed inputs, explicit standard types, and headers.
- Derive the delta and byte totals; do not hard-code output results.
- Do not use int8_t, input, casts, or a using namespace directive.
Exact expected output:
Packet delta: -1200
Field count: 3
Payload size correct: true
Completion checklist:
- packetDelta is received minus sent.
- payloadBytes multiplies one field's size by the number of fields.
- The C++20 build is warning-free and all three lines match exactly.
Run from project root: ./course check 4.6
*/
#include <cstddef>
#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t received{ 48'000 };
    std::int32_t sent{ 49'200 };
    std::int32_t packetDelta{ received - sent};

    std::size_t fieldBytes{ sizeof(std::int32_t) };
    std::size_t fieldCount{ 3 };
    std::size_t payloadBytes{ fieldBytes * fieldCount };
    bool payloadSizeCorrect{ payloadBytes == fieldBytes * fieldCount };

    std::cout << "Packet delta: " << packetDelta << '\n';
    std::cout << "Field count: " << fieldCount << '\n';
    std::cout << "Payload size correct: " << std::boolalpha << payloadSizeCorrect << '\n';
    return 0;
}
