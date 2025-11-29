#include "Workshop.h"
#include "../people/Instructor.h"

Workshop::Workshop(std::string title,
                   Hall& hall,
                   int maxParticipants)
    : Event(std::move(title), "TBD", &hall, maxParticipants) {}

void Workshop::assignInstructor(Instructor& instructor) {
    instructor_ = &instructor;
    organizerName_ = instructor.name();
}

std::string Workshop::getInfo() const {
    std::string hallName = location_ ? location_->name() : "Unknown";
    std::string instructorName = instructor_ ? instructor_->name() : "No instructor assigned";
    return "Workshop: \"" + title_ + "\" by " + instructorName +
           " in " + hallName +
           " (" + std::to_string(participantCount()) + "/" +
           std::to_string(maxParticipants()) + " participants)";
}