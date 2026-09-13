#include <cstddef>
#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t received{ 48'000 };
    std::int32_t sent{ 49'200 };
    std::int32_t packetDelta{ received - sent };

    std::size_t fieldBytes{ sizeof(std::int32_t) };
    std::size_t fieldCount{ 3 };
    std::size_t payloadBytes{ fieldBytes * fieldCount };
    bool payloadSizeCorrect{ payloadBytes == fieldBytes * fieldCount };

    std::cout << "Packet delta: " << packetDelta << '\n';
    std::cout << "Field count: " << fieldCount << '\n';
    std::cout << "Payload size correct: " << std::boolalpha << payloadSizeCorrect << '\n';
    return 0;
}
