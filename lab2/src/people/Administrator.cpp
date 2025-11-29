#include "Administrator.h"
#include "../exceptions/MuseumExceptions.h"
#include <stdexcept>

Administrator::Administrator(std::string name,
                             std::string employeeId,
                             std::string specialization,
                             short age,
                             char gender)
    : Employee(std::move(name), std::move(employeeId), "Administrator", age, gender),
      specialization_(std::move(specialization)) {}

void Administrator::organizeExhibit(Hall& hall, Exhibit& exhibit) const {
    if (!hall.isClean())
        throw HallIsDirtyException();

    exhibit.setOpen(true);
}
void Administrator::organizeLecture(Hall& hall, Lecture& lecture) const {
    if (hall.capacity() < 10)
        throw HallIsSmallException();

    if (!hall.isClean())
        throw HallIsDirtyException();

    lecture.setLocation(hall);
}

void Administrator::organizeWorkshop(Hall& hall, Workshop& workshop) const {
    if (hall.capacity() < 5)
        throw HallIsSmallException();

    if (!hall.isClean())
        throw HallIsDirtyException();

    workshop.setLocation(hall);
}

void Administrator::addArtworkToExhibit(Exhibit& exhibit, Artwork* artwork) const {
    if (!artwork)
        throw std::invalid_argument("Artwork cannot be null");

    exhibit.addArtwork(artwork);
}

void Administrator::openExhibit(Exhibit& exhibit) const {
    if (exhibit.size() == 0)
        throw std::invalid_argument("Exhibit cannot be empty");

    exhibit.setOpen(true);
}

void Administrator::assignLecturerToLecture(Lecture& lecture, Lecturer& lecturer) const {
    lecture.assignLecturer(lecturer);
}

void Administrator::assignInstructorToWorkshop(Workshop& workshop, Instructor& instructor) const {
    workshop.assignInstructor(instructor);
}