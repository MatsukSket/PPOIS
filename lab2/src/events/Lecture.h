#pragma once

#include "Event.h"
#include <string>

class Lecturer; 

class Lecture : public Event {
public:
    Lecture(std::string title,
            std::string topic,
            Hall& hall,
            int maxParticipants = 50);

    void assignLecturer(Lecturer& lecturer);
    Lecturer* lecturer() const { return lecturer_; }

    std::string topic() const { return topic_; }
    std::string getInfo() const override;

private:
    std::string topic_;
    Lecturer* lecturer_ = nullptr;
};