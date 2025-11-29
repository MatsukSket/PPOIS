#include "Hall.h"
#include "../exceptions/MuseumExceptions.h"

Hall::Hall(std::string name, int capacity)
    : Room(std::move(name)), capacity_(capacity) {
    if (capacity_ <= 0)
        throw InvalidHallCapacityException();
}

std::string Hall::getDescription() const {
    return "Hall '" + name() + "': capacity " + std::to_string(capacity_) +
           ", current visitors: " + std::to_string(currentVisitors_);
}

void Hall::removeVisitor() {
    if (currentVisitors_ > 0) {
        currentVisitors_--;
    }
}

void Hall::addVisitor() {
    if (currentVisitors_ < capacity_)
        currentVisitors_++;
    else 
        throw HallOvercrowdedException();
        
}