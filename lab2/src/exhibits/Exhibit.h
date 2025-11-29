#pragma once

#include <vector>
#include <string>
#include "Artwork.h"

class Exhibit {
public:
    explicit Exhibit(std::string name, size_t capacity = 10);

    const std::string& name() const { return name_; }
    size_t capacity() const { return capacity_; }
    size_t size() const { return artworks_.size(); }
    bool isOpen() const { return isOpen_; }
    void setOpen(bool open) { isOpen_ = open; }

    void addArtwork(Artwork* artwork);
    std::vector<std::string> getArtworkInfo() const;

private:
    std::string name_;
    size_t capacity_;
    std::vector<Artwork*> artworks_;
    bool isOpen_ = false;
    std::string curatorName_;       
    std::string theme_; 
};