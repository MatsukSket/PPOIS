#include "spaces/Museum.h"
#include "people/Employee.h"
#include "people/Visitor.h"
#include "finance/Ticket.h"
#include "exhibits/Exhibit.h"
#include "spaces/Hall.h"
#include "exceptions/MuseumExceptions.h"
#include <UnitTest++/UnitTest++.h>

TEST(Museum_ValidConstruction) {
    Museum museum("City Art Museum");
    CHECK_EQUAL("City Art Museum", museum.name());
    CHECK_EQUAL(0, museum.getStaffCount());
    CHECK_EQUAL(0, museum.getVisitorCount());
    CHECK_EQUAL(0, museum.getExhibitCount());
}

TEST(Museum_HireEmployee_Valid) {
    Museum museum("M");
    museum.hireEmployee(Employee("Dr. Smith", "E001", "Curator", 40, 'M'));
    CHECK_EQUAL(1, museum.getStaffCount());
    auto names = museum.listStaff();
    CHECK_EQUAL(1, names.size());
    CHECK_EQUAL("Dr. Smith", names[0]);
}

TEST(Museum_AdmitVisitor_Valid) {
    Museum museum("M");
    Visitor v("Alice", Ticket("V1", Ticket::Type::STANDARD), 20.0, 25, 'F');
    museum.admitVisitor(std::move(v));
    CHECK_EQUAL(1, museum.getVisitorCount());
    auto names = museum.listVisitors();
    CHECK_EQUAL(1, names.size());
    CHECK_EQUAL("Alice", names[0]);
}

TEST(Museum_AddExhibit_Valid) {
    Museum museum("M");
    museum.addExhibit(Exhibit("Renaissance", 10));
    CHECK_EQUAL(1, museum.getExhibitCount());
    const Exhibit* ex = museum.findExhibit("Renaissance");
    CHECK(ex != nullptr);
    CHECK_EQUAL("Renaissance", ex->name());
}

TEST(Museum_FindExhibit_NotFound) {
    Museum museum("M");
    const Exhibit* ex = museum.findExhibit("Missing");
    CHECK(ex == nullptr);
}

TEST(Museum_AdmitVisitorToExhibit_ExhibitNotFound_Throws) {
    Museum museum("M");
    Visitor v("Bob", Ticket("V2", Ticket::Type::STUDENT));
    CHECK_THROW(
        museum.admitVisitorToExhibit(std::move(v), "Unknown Exhibit"),
        ExhibitNotFoundException
    );
}

TEST(Museum_AddRoom_Valid) {
    Museum museum("M");
    museum.addRoom(std::make_unique<Hall>("Main Hall", 100));
}