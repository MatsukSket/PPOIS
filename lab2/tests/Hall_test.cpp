#include "spaces/Hall.h"
#include "exceptions/MuseumExceptions.h"
#include <UnitTest++/UnitTest++.h>

TEST(Hall_ValidConstruction) {
    Hall hall("Grand Hall", 200);
    CHECK_EQUAL("Grand Hall", hall.name());
    CHECK_EQUAL(200, hall.capacity());
    CHECK_EQUAL(0, hall.currentVisitors());
}

TEST(Hall_InvalidCapacity_Throws) {
    CHECK_THROW(Hall("Bad", -10), InvalidHallCapacityException);
    CHECK_THROW(Hall("Zero", 0), InvalidHallCapacityException);
}

TEST(Hall_AddVisitor_WithinCapacity) {
    Hall hall("Small", 2);
    hall.addVisitor();
    CHECK_EQUAL(1, hall.currentVisitors());
    hall.addVisitor();
    CHECK_EQUAL(2, hall.currentVisitors());
}

TEST(Hall_AddVisitor_ExceedsCapacity_Throws) {
    Hall hall("Tiny", 1);
    hall.addVisitor();
    CHECK_EQUAL(1, hall.currentVisitors());
    CHECK_THROW(hall.addVisitor(), HallOvercrowdedException);
}

TEST(Hall_RemoveVisitor_Valid) {
    Hall hall("EmptyTest", 10);
    hall.addVisitor();
    hall.addVisitor();
    CHECK_EQUAL(2, hall.currentVisitors());
    hall.removeVisitor();
    CHECK_EQUAL(1, hall.currentVisitors());
    hall.removeVisitor();
    CHECK_EQUAL(0, hall.currentVisitors());
}

TEST(Hall_RemoveVisitor_Empty_NoCrash) {
    Hall hall("Safe", 5);
    hall.removeVisitor(); // должно игнорироваться
    CHECK_EQUAL(0, hall.currentVisitors());
}

TEST(Hall_GetDescription_FormatsCorrectly) {
    Hall hall("Lecture", 50);
    hall.addVisitor();
    std::string desc = hall.getDescription();
    CHECK(desc.find("Lecture") != std::string::npos);
    CHECK(desc.find("capacity 50") != std::string::npos);
    CHECK(desc.find("current visitors: 1") != std::string::npos);
}