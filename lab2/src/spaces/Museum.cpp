#include "Museum.h"
#include "../exceptions/MuseumExceptions.h"
#include <algorithm>

Museum::Museum(std::string name) : name_(std::move(name)) {}

// === Персонал ===
void Museum::hireEmployee(Employee&& emp) {
    staff_.push_back(std::move(emp));
}

std::vector<std::string> Museum::listStaff() const {
    std::vector<std::string> names;
    names.reserve(staff_.size());
    for (const auto& emp : staff_) {
        names.push_back(emp.name());
    }
    return names;
}

// === Посетители ===
void Museum::admitVisitor(Visitor&& visitor) {
    visitors_.push_back(std::move(visitor));
}

void Museum::admitVisitorToExhibit(Visitor&& visitor, const std::string& exhibitName) {
    if (!findExhibit(exhibitName)) {
        throw ExhibitNotFoundException(exhibitName);
    }
    visitors_.push_back(std::move(visitor));
}

std::vector<std::string> Museum::listVisitors() const {
    std::vector<std::string> names;
    names.reserve(visitors_.size());
    for (const auto& v : visitors_) {
        names.push_back(v.name());
    }
    return names;
}

// === Выставки ===
void Museum::addExhibit(Exhibit&& exhibit) {
    exhibits_.push_back(std::move(exhibit));
}

const Exhibit* Museum::findExhibit(const std::string& name) const {
    auto it = std::find_if(exhibits_.begin(), exhibits_.end(),
        [&](const Exhibit& ex) { return ex.name() == name; });
    return (it != exhibits_.end()) ? &(*it) : nullptr;
}

// === Комнаты ===
void Museum::addRoom(std::unique_ptr<Room> room) {
    rooms_.push_back(std::move(room));
}
