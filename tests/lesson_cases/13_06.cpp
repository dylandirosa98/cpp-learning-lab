#define COURSE_TESTING
#include "main.cpp"
#undef COURSE_TESTING
#include "lab_checks.h"

int main()
{
    for(bool owns : {false,true}) {
        Lab::expect(canEdit(Access::admin,owns),"admin can edit regardless of owner");
        Lab::eq(canEdit(Access::member,owns),owns,"member ownership rule");
        Lab::expect(!canEdit(Access::guest,owns),"guest never edits");
    }
    return Lab::finish();
}
