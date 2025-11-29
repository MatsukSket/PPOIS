#include "Artwork.h"

Artwork::Artwork(std::string title, std::string artist)
    : title_(std::move(title)), artist_(std::move(artist)) {}