/* Shared runtime assertions for the visible Chapters 9-13 tests.
LearnCpp: https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/
Support code: no learner edits needed. Reports expected and actual results.
Run main.cpp locally; submit with ./course check <lesson-id>.
*/
#ifndef CPP_LEARNING_LAB_CHECKS_H
#define CPP_LEARNING_LAB_CHECKS_H
#include <cmath>
#include <csignal>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#if defined(__unix__) || defined(__APPLE__)
#include <cstdio>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace Lab
{
inline int passed{0};
inline void expect(bool condition, std::string_view label)
{
    if (!condition)
    {
        std::cerr << "FAIL: " << label << '\n';
        std::exit(1);
    }
    ++passed;
}
template <typename A, typename B>
void eq(const A& actual, const B& expected, std::string_view label)
{
    if (actual != expected)
    {
        std::cerr << "FAIL: " << label;
        if constexpr (requires { std::cerr << actual << expected; })
            std::cerr << " | expected " << expected << ", got " << actual;
        std::cerr << '\n';
        std::exit(1);
    }
    ++passed;
}
inline void near(double actual, double expected, std::string_view label)
{
    if (!std::isfinite(actual) || std::abs(actual - expected) > 1e-9)
    {
        std::cerr << "FAIL: " << label << " | expected " << expected << ", got " << actual << '\n';
        std::exit(1);
    }
    ++passed;
}
template <typename Function>
void expectAbort(Function function, std::string_view label)
{
#if defined(__unix__) || defined(__APPLE__)
    // Isolate intentional assertions: never abort the whole visible test run,
    // never produce a core dump, and distinguish assertion aborts from crashes.
    const auto child{fork()};
    expect(child >= 0, "could not start assertion test process");
    if (child == 0)
    {
        const rlimit limit{0, 0};
        setrlimit(RLIMIT_CORE, &limit);
        std::freopen("/dev/null", "w", stderr);
        function();
        std::_Exit(0);
    }
    int status{};
    expect(waitpid(child, &status, 0) == child, "could not collect assertion test");
    expect(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT, label);
#else
    (void)function;
    std::cerr << "Assertion subprocess tests require Linux or macOS: " << label << '\n';
    std::exit(1);
#endif
}
inline int finish()
{
    std::cout << "All " << passed << " tests passed. Submit with ./course check <lesson-id>.\n";
    return 0;
}
}
#endif
