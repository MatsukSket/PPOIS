#pragma once
#include "Room.h"
#include <string>

class Office : public Room {
public:
    explicit Office(std::string name);

    std::string getDescription() const override;
};