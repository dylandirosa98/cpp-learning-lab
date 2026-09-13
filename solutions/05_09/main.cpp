#include <iostream>
#include <string>
#include <string_view>

std::string_view trimBrackets(std::string_view text)
{
    text.remove_prefix(1);
    text.remove_suffix(1);
    return text;
}

int main()
{
    std::string owner{ "[stable slice]" };
    std::string_view source{ owner };
    std::string_view slice{ trimBrackets(source) };

    std::cout << "Source: " << source << '\n';
    std::cout << "Slice: " << slice << '\n';
    return 0;
}
