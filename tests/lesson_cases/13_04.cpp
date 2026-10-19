#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Lab::eq(colorName(red),std::string_view{"red"},"red label"); Lab::eq(colorName(green),std::string_view{"green"},"green label");
    Lab::eq(colorName(blue),std::string_view{"blue"},"blue label");
    Lab::eq(parseColor("red").value_or(blue),red,"parse red"); Lab::eq(parseColor("green").value_or(red),green,"parse green");
    Lab::eq(parseColor("blue").value_or(red),blue,"parse blue");
    for(std::string_view text : {"","Blue"," red","yellow"}) Lab::expect(!parseColor(text).has_value(),"reject unknown name");
    return Lab::finish();
}
