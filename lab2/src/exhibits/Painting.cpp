#include "Painting.h"

Painting::Painting(std::string title, std::string artist, std::string style, int year)
    : Artwork(std::move(title), std::move(artist)),
      style_(std::move(style)), year_(year) {}

std::string Painting::getInfo() const {
    return "Painting: \"" + title() + "\" by " + artist() +
           " (" + std::to_string(year_) + ", " + style_ + ")";
}