#include "Room.h"

Room::Room(std::string name, std::string location)
    : name_(std::move(name)), location_(std::move(location)) {}