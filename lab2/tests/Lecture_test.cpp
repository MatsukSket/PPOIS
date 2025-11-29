#include "events/Lecture.h"
#include "spaces/Hall.h"
#include "people/Lecturer.h"
#include "people/Visitor.h"
#include "finance/Ticket.h"
#include <UnitTest++/UnitTest++.h>

TEST(Lecture_Ctor_SetsDefaultOrganizer) {
    Hall hall("Lecture Hall", 60);
    Lecture lecture("Intro", "History", hall, 50);
    CHECK_EQUAL("TBD", lecture.organizerName());
}

TEST(Lecture_AssignLecturer_UpdatesOrganizerAndReference) {
    Hall hall("Hall", 50);
    Lecture lecture("AI", "Neural Nets", hall, 40);
    Lecturer lecturer("Dr. Alan", "L101", 42, 'M');

    lecture.assignLecturer(lecturer);
    CHECK_EQUAL("Dr. Alan", lecture.organizerName());
    CHECK_EQUAL(&lecturer, lecture.lecturer());
}

TEST(Lecture_GetInfo_NoLecturerAssigned) {
    Hall hall("Room", 30);
    Lecture lecture("Empty", "Void", hall, 10);
    std::string info = lecture.getInfo();
    CHECK(info.find("No lecturer assigned") != std::string::npos);
    CHECK(info.find("Empty") != std::string::npos);
    CHECK(info.find("Void") != std::string::npos);
}

TEST(Lecture_GetInfo_WithLecturerAndHall) {
    Hall hall("Grand Hall", 200);
    Lecture lecture("Cosmos", "Space", hall, 150);
    Lecturer lecturer("Dr. Nova", "L202");
    lecture.assignLecturer(lecturer);

    std::string info = lecture.getInfo();
    CHECK(info.find("Dr. Nova") != std::string::npos);
    CHECK(info.find("Grand Hall") != std::string::npos);
    CHECK(info.find("Cosmos") != std::string::npos);
    CHECK(info.find("Space") != std::string::npos);
}
