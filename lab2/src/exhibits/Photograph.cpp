#include "Photograph.h"
#include <iostream>

Photograph::Photograph(std::string title,
                       std::string photographer,
                       int year,
                       bool isColor)
    : Artwork(std::move(title), std::move(photographer)),
      year_(year),
      isColor_(isColor) {}

std::string Photograph::getInfo() const {
    return "Photograph: \"" + title() + "\" by " + artist() +
           " (" + std::to_string(year_) + ", " + (isColor_ ? "Color" : "Black & White") + ")";
}