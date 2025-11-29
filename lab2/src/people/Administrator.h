#pragma once

#include "Employee.h"
#include "../exhibits/Exhibit.h"
#include "../events/Lecture.h"
#include "../events/Workshop.h"
#include "../spaces/Hall.h"
#include <string>

class Administrator : public Employee {
public:
    explicit Administrator(std::string name,
                           std::string employeeId,
                           std::string specialization = "General",
                           short age = 0,
                           char gender = 'U');

    const std::string& specialization() const { return specialization_; }

    void organizeExhibit(Hall& hall, Exhibit& exhibit) const;
    void organizeLecture(Hall& hall, Lecture& lecture) const;
    void organizeWorkshop(Hall& hall, Workshop& workshop) const;

    void assignLecturerToLecture(Lecture& lecture, Lecturer& lecturer) const;
    void assignInstructorToWorkshop(Workshop& workshop, Instructor& instructor) const;

    void addArtworkToExhibit(Exhibit& exhibit, Artwork* artwork) const;
    void openExhibit(Exhibit& exhibit) const;

private:
    std::string specialization_;
};