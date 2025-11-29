#pragma once

#include "Souvenir.h"
#include <string>

class Postcard : public Souvenir {
public:
    Postcard(std::string name, double price, std::string location = "Museum");

    const std::string& location() const { return location_; }
    std::string getCategory() const override { return "Postcard"; }

private:
    std::string location_;
    std::string frontImage_;
    std::string backMessage_;
};