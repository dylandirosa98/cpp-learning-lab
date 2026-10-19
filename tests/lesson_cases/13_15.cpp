#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    static_assert(std::is_same_v<ScorePair<double>,Pair<double>>);
    ScorePair<int> a{2,8}; ScorePair<double> b{1.25,2.5};
    Lab::eq(maxScore<int>(a),8,"aliased integer pair"); Lab::near(maxScore<double>(b),2.5,"aliased double pair");
    Lab::eq(maxScore<int>(ScorePair<int>{-2,-5}),-2,"negative scores"); Lab::near(maxScore<double>(ScorePair<double>{3.5,3.5}),3.5,"equal scores");
    return Lab::finish();
}
