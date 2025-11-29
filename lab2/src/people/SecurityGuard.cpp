#include "SecurityGuard.h"
#include "../exceptions/MuseumExceptions.h"

SecurityGuard::SecurityGuard(std::string name, std::string employeeId, short age, char gender)
    : Employee(std::move(name), std::move(employeeId), "Security Guard", age, gender) {}

void SecurityGuard::assignRoom(Room& room) {
    assignedRoom_ = &room;
}

bool SecurityGuard::patrol() const {
    if (!assignedRoom_) 
        return true; 
    return assignedRoom_->isClean(); 
}

void SecurityGuard::enforceCleanliness() const {
    if (assignedRoom_ && !assignedRoom_->isClean()) 
        throw HallIsDirtyException();
}