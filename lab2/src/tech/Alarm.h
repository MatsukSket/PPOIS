#pragma once

#include "spaces/Room.h"

class Alarm {
public:
    explicit Alarm(Room* location);
    
    Room* getLocation() const { return location_; }
    bool isActive() const { return isActive_; }
    void activate() { isActive_ = true; }
    void deactivate() { isActive_ = false; }

private:
    Room* location_;
    bool isActive_ = false;
};