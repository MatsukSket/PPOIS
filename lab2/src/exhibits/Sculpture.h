#pragma once

#include "Artwork.h"
#include <string>

class Sculpture : public Artwork {
public:
    Sculpture(std::string title,
              std::string artist,
              std::string material = "Unknown",
              double weightKg = 0.0);

    const std::string& material() const { return material_; }
    double weightKg() const { return weightKg_; }

    std::string getInfo() const override;

private:
    std::string material_;
    double weightKg_;
};