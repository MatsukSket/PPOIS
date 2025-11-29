#include <UnitTest++/UnitTest++.h>
#include "people/Administrator.h"
#include "spaces/Hall.h"
#include "exhibits/Exhibit.h"
#include "exhibits/Painting.h"
#include "events/Lecture.h"
#include "events/Workshop.h"
#include "people/Lecturer.h"
#include "people/Instructor.h"
#include "exceptions/MuseumExceptions.h"


TEST(Administrator_Construct_Valid) {
    Administrator admin("Admin Smith", "A101", "Exhibitions", 45, 'M');
    CHECK_EQUAL("Admin Smith", admin.name());
    CHECK_EQUAL("A101", admin.employeeId());
    CHECK_EQUAL("Exhibitions", admin.specialization());
    CHECK_EQUAL("Administrator", admin.position());
}

TEST(Administrator_OrganizeExhibit_CleanHall) {
    Hall hall("Main Hall", 50);
    hall.setClean(true);
    Exhibit exhibit("Renaissance");

    Administrator admin("Admin", "A1");
    admin.organizeExhibit(hall, exhibit);

    CHECK(exhibit.isOpen());
}

TEST(Administrator_OrganizeExhibit_DirtyHall_Throws) {
    Hall hall("Dirty Hall", 20);
    Exhibit exhibit("Art");

    Administrator admin("Admin", "A1");
    CHECK_THROW(admin.organizeExhibit(hall, exhibit), HallIsDirtyException);
}


TEST(Administrator_OrganizeLecture_Valid) {
    Hall hall("Lecture Hall", 15);
    hall.setClean(true);
    Lecture lecture("Impressionism", "Monet", hall);

    Administrator admin("Admin", "A1");
    admin.organizeLecture(hall, lecture);

    CHECK_EQUAL(&hall, lecture.location());
}

TEST(Administrator_OrganizeLecture_HallTooSmall_Throws) {
    Hall hall("Small Room", 5);
    hall.setClean(true);
    Lecture lecture("Art", "Topic", hall);

    Administrator admin("Admin", "A1");
    CHECK_THROW(admin.organizeLecture(hall, lecture), HallIsSmallException);
}

TEST(Administrator_OrganizeLecture_DirtyHall_Throws) {
    Hall hall("Dirty Lecture Hall", 20);
    Lecture lecture("Art", "Topic", hall);

    Administrator admin("Admin", "A1");
    CHECK_THROW(admin.organizeLecture(hall, lecture), HallIsDirtyException);
}


TEST(Administrator_OrganizeWorkshop_Valid) {
    Hall hall("Workshop Room", 8); 
    hall.setClean(true);
    Workshop workshop("Painting", hall);

    Administrator admin("Admin", "A1");
    admin.organizeWorkshop(hall, workshop);

    CHECK_EQUAL(&hall, workshop.location());
}

TEST(Administrator_OrganizeWorkshop_HallTooSmall_Throws) {
    Hall hall("Tiny Room", 3);
    hall.setClean(true);
    Workshop workshop("Craft", hall);

    Administrator admin("Admin", "A1");
    CHECK_THROW(admin.organizeWorkshop(hall, workshop), HallIsSmallException);
}

TEST(Administrator_OrganizeWorkshop_DirtyHall_Throws) {
    Hall hall("Dirty Workshop", 10);
    Workshop workshop("Art", hall);

    Administrator admin("Admin", "A1");
    CHECK_THROW(admin.organizeWorkshop(hall, workshop), HallIsDirtyException);
}



TEST(Administrator_AddArtwork_Valid) {
    Exhibit exhibit("Masters");
    Painting painting("Mona Lisa", "Da Vinci");

    Administrator admin("Admin", "A1");
    admin.addArtworkToExhibit(exhibit, &painting);

    CHECK_EQUAL(1, exhibit.size());
}

TEST(Administrator_AddArtwork_Null_Throws) {
    Exhibit exhibit("Empty");
    Administrator admin("Admin", "A1");

    CHECK_THROW(admin.addArtworkToExhibit(exhibit, nullptr), std::invalid_argument);
}


TEST(Administrator_OpenExhibit_Valid) {
    Exhibit exhibit("Exhibit");
    Painting p("Art", "Artist");
    exhibit.addArtwork(&p);

    Administrator admin("Admin", "A1");
    admin.openExhibit(exhibit);

    CHECK(exhibit.isOpen());
}

TEST(Administrator_OpenExhibit_Empty_Throws) {
    Exhibit exhibit("Empty");

    Administrator admin("Admin", "A1");
    CHECK_THROW(admin.openExhibit(exhibit), std::invalid_argument);
}


TEST(Administrator_AssignLecturerToLecture) {
    Hall hall("Hall", 20);
    hall.setClean(true);
    Lecture lecture("Art", "Topic", hall);
    Lecturer lecturer("Dr. Smith", "L1");

    Administrator admin("Admin", "A1");
    admin.assignLecturerToLecture(lecture, lecturer);

    CHECK_EQUAL(&lecturer, lecture.lecturer());
    CHECK_EQUAL("Dr. Smith", lecture.organizerName());
}

TEST(Administrator_AssignInstructorToWorkshop) {
    Hall hall("Workshop Hall", 10);
    hall.setClean(true);
    Workshop workshop("Painting", hall);
    Instructor instructor("Master Artist", "W1");

    Administrator admin("Admin", "A1");
    admin.assignInstructorToWorkshop(workshop, instructor);

    CHECK_EQUAL(&instructor, workshop.instructor());
    CHECK_EQUAL("Master Artist", workshop.organizerName());
}