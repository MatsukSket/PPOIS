#pragma once

#include "Employee.h"
#include "../spaces/Room.h"

class SecurityGuard : public Employee {
public:
    explicit SecurityGuard(std::string name,
                           std::string employeeId,
                           short age = 0,
                           char gender = 'U');

    void assignRoom(Room& room);
    Room* assignedRoom() const { return assignedRoom_; }

    bool patrol() const;
    void enforceCleanliness() const;

private:
    Room* assignedRoom_ = nullptr;
};