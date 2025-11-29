#pragma once
#include "Human.h"
#include <string>

class Employee : public Human {
public:
    explicit Employee(std::string name,
                      std::string employeeId,
                      std::string position = "Staff",
                      short age = 0,
                      char gender = 'U');

    const std::string& employeeId() const noexcept { return employeeId_; }
    const std::string& position() const noexcept { return position_; }

private:
    std::string employeeId_;
    std::string position_;
    std::string department_;
};