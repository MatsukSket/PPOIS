#pragma once

#include "Employee.h"
#include "../events/Workshop.h"

class Instructor : public Employee {
public:
    explicit Instructor(std::string name,
                        std::string employeeId,
                        short age = 0,
                        char gender = 'U');

    std::string conductWorkshop(const Workshop& workshop) const;
};