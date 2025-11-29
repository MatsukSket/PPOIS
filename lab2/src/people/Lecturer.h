#pragma once

#include "Employee.h"
#include "../events/Lecture.h"

class Lecturer : public Employee {
public:
    explicit Lecturer(std::string name,
                      std::string employeeId,
                      short age = 0,
                      char gender = 'U');

    std::string conductLecture(const Lecture& lecture) const;
};