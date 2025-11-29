#include <UnitTest++/UnitTest++.h>
#include "people/Lecturer.h"
#include "events/Lecture.h"
#include "spaces/Hall.h"
#include "exceptions/MuseumExceptions.h"

TEST(Lecturer_ConductLecture_AssignedAndLocated) {
    Hall hall("Auditorium", 100);
    Lecture lecture("Intro to Art", "Renaissance", hall, 50);
    Lecturer lecturer("Dr. Smith", "L001", 45, 'M');
    lecture.assignLecturer(lecturer);

    std::string result = lecturer.conductLecture(lecture);
    CHECK(result.find("Dr. Smith") != std::string::npos);
    CHECK(result.find("Intro to Art") != std::string::npos);
}

TEST(Lecturer_ConductLecture_NotAssigned_Throws) {
    Hall hall("Hall", 50);
    Lecture lecture("Physics", "Quantum", hall);
    Lecturer lecturer("Dr. Lee", "L002");

    CHECK_THROW(lecturer.conductLecture(lecture), std::runtime_error);
}

TEST(Lecturer_ConductLecture_NoLocation_Throws) {
    Hall hall("Hall", 30);
    Lecture lecture("Math", "Calculus", hall, 30);
    Lecturer lecturer("Dr. Kim", "L003");
    lecture.assignLecturer(lecturer);

    CHECK_THROW(lecturer.conductLecture(lecture), EventHasNoLocationException);
}