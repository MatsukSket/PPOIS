#include "Sculpture.h"
#include <iostream>

Sculpture::Sculpture(std::string title,
                     std::string artist,
                     std::string material,
                     double weightKg)
    : Artwork(std::move(title), std::move(artist)),
      material_(std::move(material)),
      weightKg_(weightKg) {}

std::string Sculpture::getInfo() const {
    return "Sculpture: \"" + title() + "\" by " + artist() +
           " (" + material_ + ", " + std::to_string(weightKg_) + " kg)";
}