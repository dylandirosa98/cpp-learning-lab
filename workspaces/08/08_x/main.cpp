/*
Lesson 8.x - Chapter 8 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-8-summary-and-quiz/

Problem:
Implement scanSystems, a launch-readiness scan over a string of status codes. G increments go, H
increments hold, S increments scrub and immediately stops the scan. Each G/H/S also increments
checked. T (test mode) and any unknown character are ignored. Return verdict "scrubbed" if scrub >
0, otherwise "on hold" if hold > 0 or go == 0, otherwise "go". Read characters by index with
codes[index] and codes.size(). Practice a for loop, switch, continue, and early termination; the
reporting/demo main is already supplied. Return the actual tallies, not formatted strings.

Expected results (examples):
- scanSystems("GTGHS G") -> go=2, hold=1, scrub=1, checked=4, verdict="scrubbed"
- scanSystems("GG") -> go=2, hold=0, scrub=0, checked=2, verdict="go"
- scanSystems("GHT") -> go=1, hold=1, scrub=0, checked=2, verdict="on hold"
- scanSystems("") -> all tallies 0, verdict="on hold"
- scanSystems("SGG") -> go=0, hold=0, scrub=1, checked=1, verdict="scrubbed"

Implement the function body; main is only a supplied demo.
The checker tests multiple calls, including edge cases. No source-token checks.
Run from project root: ./course check 8.x
*/
#include <iostream>
#include <string_view>

struct ScanResult {
    int go{0};
    int hold{0};
    int scrub{0};
    int checked{0};
    std::string_view verdict{"on hold"};
};

ScanResult scanSystems(std::string_view codes) {
    // TODO: Implement the behavior described above.
    ScanResult newscan{};
    for (int i{}; i < static_cast<int>(codes.length()); i++) {
        switch (codes[i]) {
        case 'G':
            newscan.go++;
            newscan.checked++;
            break;
        case 'H':
            newscan.hold++;
            newscan.checked++;
            break;
        case 'S':
            newscan.scrub++;
            newscan.checked++;
            goto checkpoint;
        default:
            break;
        }
    }
checkpoint:
    if (newscan.scrub > 0) {
        newscan.verdict = "scrubbed";
    } else if (newscan.hold > 0 || newscan.go == 0) {
        newscan.verdict = "on hold";
    } else {
        newscan.verdict = "go";
    }
    return newscan;
}

int main() {
    const auto result{scanSystems("GTGHSG")};
    std::cout << "GO: " << result.go << "\nHOLD: " << result.hold << "\nSCRUB: " << result.scrub
              << "\nChecked: " << result.checked << "\nVerdict: " << result.verdict << '\n';
    return 0;
}
