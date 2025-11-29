#pragma once

#include "Employee.h"
#include "../spaces/Room.h"

class Janitor : public Employee {
public:
    explicit Janitor(std::string name,
                     std::string employeeId,
                     short age = 0,
                     char gender = 'U');

    void clean(Room& room) const;
};