#include "Event.h"
#include "exceptions/MuseumExceptions.h"

Event::Event(std::string title,
             std::string organizerName,
             Hall* location,
             int maxParticipants)
    : title_(std::move(title)),
      organizerName_(std::move(organizerName)),
      location_(location),
      maxParticipants_(maxParticipants) {
    if (maxParticipants_ <= 0) 
        throw std::invalid_argument("Max participants must be positive");
}

void Event::addParticipant(Visitor* visitor) {
    if (!visitor) return;
    if (participants_.size() >= static_cast<size_t>(maxParticipants_)) 
        throw HallOvercrowdedException();
        
    participants_.push_back(visitor);
}