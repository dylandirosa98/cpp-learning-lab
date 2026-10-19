/*
Lesson 13.x - Chapter 13 summary and quiz
LearnCpp: https://www.learncpp.com/cpp-tutorial/chapter-13-summary-and-quiz/

Problem:
Implement sell(inventory,quantity,unitPrice), returning SaleResult. Invalid quantity <= 0 or
unitPrice < 0 returns {SaleError::invalid,0,currentStock}. If quantity exceeds stock return
{SaleError::shortStock,0,currentStock}. Otherwise reduce stock, increase cash by
quantity*unitPrice, and return {SaleError::ok,total,newStock}. On failure leave inventory
unchanged. Initial stock/cash are nonnegative and tested arithmetic fits int. Free items
(unitPrice=0) are valid.

Expected results (examples):
- Inventory{5,10}, sell(...,2,3) -> stock 3, cash 16, result {ok,6,3}
- too many items -> shortStock, unchanged inventory
- zero quantity -> invalid, unchanged inventory

Read lesson.md for explanations; hints.md has optional progressive hints.
Implement the TODO functions/API, not the supplied tests below them.
Alt+R: runs this file's visible tests through the lesson CMake target (no submission).
Submit from the repository root: ./course check 13.x
You can also run: cmake -S . -B build && cmake --build build && ./build/lesson_13_x
from this lesson directory. C++20 is required. No source-token checks apply.
*/
#include <iostream>
#include <string>
#include <string_view>


enum class SaleError { ok, invalid, shortStock };
struct Inventory { int stock{}; int cash{}; };
struct SaleResult { SaleError error{SaleError::invalid}; int total{}; int remaining{}; };

SaleResult sell(Inventory& inventory, int quantity, int unitPrice)
{
    if(quantity<=0 || unitPrice<0) return {SaleError::invalid,0,inventory.stock};
    if(quantity>inventory.stock) return {SaleError::shortStock,0,inventory.stock};
    const int total{quantity*unitPrice};
    inventory.stock-=quantity;
    inventory.cash+=total;
    return {SaleError::ok,total,inventory.stock};
}

// ==================== VISIBLE TESTS ====================
// These are executable examples, not output statements for you to fill in.
// The checker has an independent copy. Add your own tests; keep these too.
#ifndef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    Inventory inventory{5,10}; auto good{sell(inventory,2,3)};
    Lab::eq(good.error,SaleError::ok,"successful sale status"); Lab::eq(good.total,6,"sale total"); Lab::eq(good.remaining,3,"result stock");
    Lab::eq(inventory.stock,3,"stock debited"); Lab::eq(inventory.cash,16,"cash credited");
    auto shortStock{sell(inventory,4,3)}; Lab::eq(shortStock.error,SaleError::shortStock,"insufficient stock status");
    Lab::eq(shortStock.total,0,"failure has no revenue"); Lab::eq(shortStock.remaining,3,"failed sale reports unchanged stock");
    Lab::eq(inventory.stock,3,"failed sale preserves stock"); Lab::eq(inventory.cash,16,"failed sale preserves cash");
    auto invalid{sell(inventory,0,3)}; Lab::eq(invalid.error,SaleError::invalid,"zero quantity invalid");
    Lab::eq(sell(inventory,1,-1).error,SaleError::invalid,"negative price invalid");
    auto free{sell(inventory,3,0)}; Lab::eq(free.error,SaleError::ok,"free items valid"); Lab::eq(free.remaining,0,"sell remaining stock"); Lab::eq(inventory.cash,16,"free sale no revenue");
    Lab::eq(sell(inventory,1,1).error,SaleError::shortStock,"empty inventory");
    return Lab::finish();
}
#endif
