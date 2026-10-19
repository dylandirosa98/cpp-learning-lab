#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    const auto mixed{Pair{2,5.5}}; static_assert(std::is_same_v<std::remove_cv_t<decltype(mixed)>,Pair<double>>);
    Lab::near(mixed.first,2.0,"mixed first member"); Lab::near(mixed.second,5.5,"mixed second member");
    Lab::near(spanOf(mixed),3.5,"mixed span"); Lab::eq(spanOf(Pair{8,3}),5,"integer span");
    Lab::eq(spanOf(Pair{3,8}),5,"reversed span"); Lab::near(spanOf(Pair{1.25,1.25}),0.0,"equal double span");
    return Lab::finish();
}
