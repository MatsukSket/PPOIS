#pragma once

#include "spaces/Hall.h"
#include "people/Visitor.h"
#include <string>
#include <vector>

class Event {
public:
    explicit Event(std::string title,
                   std::string organizerName = "Staff",
                   Hall* location = nullptr,
                   int maxParticipants = 100);
    virtual ~Event() = default;

    const std::string& title() const { return title_; }
    const std::string& organizerName() const { return organizerName_; }
    Hall* location() const { return location_; }
    int maxParticipants() const { return maxParticipants_; }
    size_t participantCount() const { return participants_.size(); }

    void setLocation(Hall& hall) { location_ = &hall; }
    void addParticipant(Visitor* visitor); // общий метод

    virtual std::string getInfo() const = 0;

protected:
    std::string title_;
    std::string organizerName_;
    Hall* location_ = nullptr;
    int maxParticipants_;
    std::vector<Visitor*> participants_;
    bool registrationRequired_;
};