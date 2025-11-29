#include "Janitor.h"

Janitor::Janitor(std::string name, 
                 std::string employeeId, 
                 short age, 
                 char gender)
    : Employee(std::move(name), std::move(employeeId), "Janitor", age, gender) {}

void Janitor::clean(Room& room) const {
    room.setClean(true);
}