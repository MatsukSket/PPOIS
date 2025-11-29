#include "Exhibit.h"
#include "../exceptions/MuseumExceptions.h"
#include <stdexcept>

Exhibit::Exhibit(std::string name, size_t capacity)
    : name_(std::move(name)), capacity_(capacity) {}

void Exhibit::addArtwork(Artwork* artwork) {
    if (!artwork) 
        throw std::invalid_argument("Artwork pointer is null");
        
    if (artworks_.size() >= capacity_) 
        throw std::runtime_error("Exhibit is full");
        
    artworks_.push_back(artwork);
}

std::vector<std::string> Exhibit::getArtworkInfo() const {
    std::vector<std::string> info;
    for (const auto* artwork : artworks_) 
        info.push_back(artwork->getInfo());
        
    return info;
}