#include "events/Lecture.h"
#include "events/Workshop.h"
#include "spaces/Hall.h"
#include "people/Visitor.h"
#include "finance/Ticket.h"
#include "exceptions/MuseumExceptions.h"
#include <UnitTest++/UnitTest++.h>

TEST(Event_Ctor_InvalidMaxParticipants_Throws) {
    Hall hall("TestHall", 50);
    CHECK_THROW(
        Lecture("Test", "Topic", hall, -5),
        std::invalid_argument
    );
    CHECK_THROW(
        Workshop("Test", hall, 0),
        std::invalid_argument
    );
}

TEST(Event_AddParticipant_NullPtr_Ignored) {
    Hall hall("Hall", 10);
    Lecture lecture("Lec", "Art", hall, 2);
    lecture.addParticipant(nullptr);
    CHECK_EQUAL(0, lecture.participantCount());
}

TEST(Event_AddParticipant_ExceedsCapacity_Throws) {
    Hall hall("Hall", 10);
    Workshop workshop("WS", hall, 1);
    
    Ticket ticket("V1", Ticket::Type::STANDARD);
    Visitor v1("Alice", ticket, 10.0, 25, 'F');
    Visitor v2("Bob", ticket, 10.0, 30, 'M');

    workshop.addParticipant(&v1);
    CHECK_EQUAL(1, workshop.participantCount());

    CHECK_THROW(workshop.addParticipant(&v2), HallOvercrowdedException);
}

TEST(Event_Getters_ReturnCorrectValues) {
    Hall hall("Auditorium", 100);
    Lecture lecture("Quantum Physics", "Wave Functions", hall, 80);
    CHECK_EQUAL("Quantum Physics", lecture.title());
    CHECK_EQUAL(80, lecture.maxParticipants());
    CHECK_EQUAL(&hall, lecture.location());
    CHECK_EQUAL(0, lecture.participantCount());
}
