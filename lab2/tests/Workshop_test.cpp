#include "events/Workshop.h"
#include "spaces/Hall.h"
#include "people/Instructor.h"
#include "people/Visitor.h"
#include "finance/Ticket.h"
#include <UnitTest++/UnitTest++.h>

TEST(Workshop_Ctor_SetsDefaultOrganizer) {
    Hall hall("Studio", 20);
    Workshop workshop("Pottery", hall, 10);
    CHECK_EQUAL("TBD", workshop.organizerName());
}

TEST(Workshop_AssignInstructor_UpdatesOrganizerAndReference) {
    Hall hall("Craft Room", 15);
    Workshop workshop("Knitting", hall, 8);
    Instructor instructor("Ms. Craft", "I101", 35, 'F');

    workshop.assignInstructor(instructor);
    CHECK_EQUAL("Ms. Craft", workshop.organizerName());
    CHECK_EQUAL(&instructor, workshop.instructor());
}

TEST(Workshop_GetInfo_NoInstructorAssigned) {
    Hall hall("Small Room", 10);
    Workshop workshop("Test", hall, 5);
    std::string info = workshop.getInfo();
    CHECK(info.find("No instructor assigned") != std::string::npos);
    CHECK(info.find("Test") != std::string::npos);
}

TEST(Workshop_GetInfo_WithInstructorAndHall) {
    Hall hall("Art Lab", 12);
    Workshop workshop("Painting", hall, 10);
    Instructor instructor("Mr. Brush", "I202");
    workshop.assignInstructor(instructor);

    std::string info = workshop.getInfo();
    CHECK(info.find("Mr. Brush") != std::string::npos);
    CHECK(info.find("Art Lab") != std::string::npos);
    CHECK(info.find("Painting") != std::string::npos);
}
