/*
Lesson 13.11 - Struct miscellany
LearnCpp: https://www.learncpp.com/cpp-tutorial/struct-miscellany/

Problem:
Implement movePlayer(player,dx,dy), changing only the nested position coordinates of the
caller's Player. Preserve name and health exactly. Position is a nested program-defined member
type, not an independent global position variable. Sums fit int.

Expected results (examples):
- Player{"Ada",{2,3},90} moved by (4,-1) -> position {6,2}, name/health unchanged

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.11
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_11
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


struct Position { int x{}; int y{}; };
struct Player { std::string name; Position position; int health{100}; };

void movePlayer(Player& player, int dx, int dy)
{
    // TODO: Implement the contract above.
    (void)player; (void)dx; (void)dy;
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Player p{"Ada",{2,3},90}; movePlayer(p,4,-1); Lab::eq(p.position.x,6,"nested x updated"); Lab::eq(p.position.y,2,"nested y updated");
    Lab::eq(p.name,std::string{"Ada"},"name preserved"); Lab::eq(p.health,90,"health preserved");
    movePlayer(p,-6,-2); Lab::eq(p.position.x,0,"nested x returns to origin"); Lab::eq(p.position.y,0,"nested y returns to origin");
    return Lab::finish();
}
#endif
