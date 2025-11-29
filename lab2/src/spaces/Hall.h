#pragma once

#include "Room.h"
#include <string>

class Hall : public Room {
public:
    Hall(std::string name, int capacity = 50);

    int capacity() const { return capacity_; }
    int currentVisitors() const { return currentVisitors_; }
    std::string getDescription() const override;

    void addVisitor();
    void removeVisitor();

    bool isOvercrowded() const { return currentVisitors_ > capacity_; }

private:
    int capacity_;
    int currentVisitors_ = 0;
    std::string lightingType_;
    double areaSqM_;
};