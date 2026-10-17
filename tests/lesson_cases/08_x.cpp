#define main learner_main
#include "main.cpp"
#undef main
#include "check.h"
int main()
{
    for (const std::string_view codes : {"", "T", "?t ", "G", "GG", "H", "GHT", "GTGHSG", "SGG", "HSG", "TG?G", "GGGTHHH", "TTSTG"})
    {
        int go{0}, hold{0}, scrub{0};
        for (char code : codes)
        {
            if (code == 'S') { scrub = 1; break; }
            if (code == 'G') ++go;
            if (code == 'H') ++hold;
        }
        const auto result{scanSystems(codes)};
        checkEqual(result.go, go, "scanSystems: GO tally");
        checkEqual(result.hold, hold, "scanSystems: HOLD tally");
        checkEqual(result.scrub, scrub, "scanSystems: stop at SCRUB");
        checkEqual(result.checked, go + hold + scrub, "scanSystems: ignored codes not counted");
        const std::string_view verdict{scrub ? "scrubbed" : hold || !go ? "on hold" : "go"};
        checkEqual(result.verdict, verdict, "scanSystems: verdict priority");
    }
    return 0;
}
