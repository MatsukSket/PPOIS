#include "Employee.h"

Employee::Employee(std::string name,
                   std::string employeeId,
                   std::string position,
                   short age,
                   char gender)
    : Human(std::move(name), age, gender),
      employeeId_(std::move(employeeId)),
      position_(std::move(position)) {
    if (employeeId_.empty()) {
        throw std::invalid_argument("Employee ID must not be empty");
    }
}