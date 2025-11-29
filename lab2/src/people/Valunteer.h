#pragma once
#include "Human.h"
#include <string>

class Volunteer : public Human {
public:
    Volunteer(std::string name,
              short age,
              char gender,
              std::string department = "General",
              int hoursPerWeek = 0,
              std::string supervisor = "Admin",
              bool hasTraining = false)
    : Human(std::move(name), age, gender),
      department_(std::move(department)),
      hoursPerWeek_(hoursPerWeek),
      supervisor_(std::move(supervisor)),
      hasTraining_(hasTraining) {}

    const std::string& department() const noexcept { return department_; }
    int hoursPerWeek() const noexcept { return hoursPerWeek_; }
    const std::string& supervisor() const noexcept { return supervisor_; }
    bool hasTraining() const noexcept { return hasTraining_; }

private:
    std::string department_;
    int hoursPerWeek_;
    std::string supervisor_;
    bool hasTraining_;
};