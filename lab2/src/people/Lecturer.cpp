#include "Lecturer.h"
#include "../exceptions/MuseumExceptions.h"
#include <stdexcept>

Lecturer::Lecturer(std::string name, std::string employeeId, short age, char gender)
    : Employee(std::move(name), std::move(employeeId), "Lecturer", age, gender) {}

std::string Lecturer::conductLecture(const Lecture& lecture) const {
    if (lecture.lecturer() != this) {
        throw std::runtime_error("This lecturer is not assigned to the lecture");
    }
    if (!lecture.location()) {
        throw EventHasNoLocationException();
    }
    return "Lecturer " + name() + " conducted: " + lecture.title();
}