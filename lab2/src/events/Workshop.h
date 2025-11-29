#pragma once

#include "Event.h"
#include <string>

class Instructor;

class Workshop : public Event {
public:
    Workshop(std::string title,
             Hall& hall,
             int maxParticipants = 20);

    void assignInstructor(Instructor& instructor);
    Instructor* instructor() const { return instructor_; }

    std::string getInfo() const override;

private:
    Instructor* instructor_ = nullptr;
};