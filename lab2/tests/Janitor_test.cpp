#include <UnitTest++/UnitTest++.h>
#include "people/Janitor.h"
#include "spaces/Hall.h"
#include "spaces/Cafe.h" 
#include "spaces/Office.h"

TEST(Janitor_Clean_Hall) {
    Hall hall("Egypt", 20);
    Janitor janitor("Bob", "J1");
    
    janitor.clean(hall);
    CHECK(hall.isClean());
}

TEST(Janitor_Clean_Office) {
    Office office("Staff Room");
    Janitor janitor("Alice", "J2");
    
    janitor.clean(office);
    CHECK(office.isClean());
}