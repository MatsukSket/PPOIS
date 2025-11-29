#include "Lecture.h"
#include "../people/Lecturer.h"

Lecture::Lecture(std::string title,
                 std::string topic,
                 Hall& hall,
                 int maxParticipants)
    : Event(std::move(title), "TBD", &hall, maxParticipants), 
      topic_(std::move(topic)) {}

void Lecture::assignLecturer(Lecturer& lecturer) {
    lecturer_ = &lecturer;
    organizerName_ = lecturer.name();
}

std::string Lecture::getInfo() const {
    std::string hallName = location_ ? location_->name() : "Unknown";
    std::string lecturerName = lecturer_ ? lecturer_->name() : "No lecturer assigned";
    return "Lecture: \"" + title_ + "\" by " + lecturerName +
           " on " + topic_ + " in " + hallName +
           " (" + std::to_string(participantCount()) + "/" +
           std::to_string(maxParticipants()) + " participants)";
}