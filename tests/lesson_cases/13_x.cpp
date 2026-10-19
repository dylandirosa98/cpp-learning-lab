#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
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
