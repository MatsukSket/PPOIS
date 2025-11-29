#pragma once

#include "Employee.h"
#include "../spaces/Room.h" // ← теперь принимает любой Room

class SecurityGuard : public Employee {
public:
    explicit SecurityGuard(std::string name,
                           std::string employeeId,
                           short age = 0,
                           char gender = 'U');

    // Устанавливает комнату для патрулирования
    void assignRoom(Room& room);
    Room* assignedRoom() const { return assignedRoom_; }

    // Проверяет комнату
    bool patrol() const;
    void enforceCleanliness() const;

private:
    Room* assignedRoom_ = nullptr;
};