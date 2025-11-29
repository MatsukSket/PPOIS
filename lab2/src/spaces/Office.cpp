#include "Office.h"

Office::Office(std::string name)
    : Room(std::move(name), "Staff Area") {}

std::string Office::getDescription() const {
    std::string cleanStatus = isClean() ? "clean" : "dirty";
    return "Office '" + name() + "': " + cleanStatus;
}