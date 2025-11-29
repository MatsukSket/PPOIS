#pragma once

#include <string>
#include "../exceptions/MuseumExceptions.h"

class Room {
public:
    explicit Room(std::string name, std::string location = "Main Building");
    virtual ~Room() = default;

    const std::string& name() const noexcept { return name_; }
    const std::string& location() const noexcept { return location_; }

    bool isClean() const noexcept { return isClean_; }
    void setClean(bool clean) noexcept { isClean_ = clean; }

    virtual std::string getDescription() const = 0;

protected:
    std::string name_;
    std::string location_;
    bool isClean_ = false; 
    int floorNumber_;
};