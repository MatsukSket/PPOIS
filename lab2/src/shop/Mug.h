#pragma once

#include "Souvenir.h"
#include <string>

class Mug : public Souvenir {
public:
    Mug(std::string name, double price, std::string material = "Ceramic");

    const std::string& material() const { return material_; }
    std::string getCategory() const override { return "Mug"; }

private:
    std::string material_;
    int capacityMl_;
    bool dishwasherSafe_;
};