#include "Instructor.h"
#include "../exceptions/MuseumExceptions.h"
#include <stdexcept>

Instructor::Instructor(std::string name, std::string employeeId, short age, char gender)
    : Employee(std::move(name), std::move(employeeId), "Workshop Master", age, gender) {}

std::string Instructor::conductWorkshop(const Workshop& workshop) const {
    if (workshop.instructor() != this) {
        throw std::runtime_error("This instructor is not assigned to the workshop");
    }
    if (!workshop.location()) {
        throw EventHasNoLocationException();
    }
    return "Instructor " + name() + " conducted: " + workshop.title();
}