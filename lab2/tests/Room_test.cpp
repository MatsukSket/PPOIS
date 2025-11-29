#include "spaces/Hall.h"
#include "spaces/Office.h"
#include <UnitTest++/UnitTest++.h>

TEST(Room_SetClean_TogglesState) {
    Hall hall("Test Hall", 50);
    CHECK(!hall.isClean());
    hall.setClean(true);
    CHECK(hall.isClean());
    hall.setClean(false);
    CHECK(!hall.isClean());
}

TEST(Room_Description_IsVirtual) {
    Office office("Admin");
    Hall hall("Auditorium", 100);
    CHECK(office.getDescription().find("Office") != std::string::npos);
    CHECK(hall.getDescription().find("Hall") != std::string::npos);
}