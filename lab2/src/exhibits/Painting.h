#pragma once

#include "Artwork.h"
#include <string>

class Painting : public Artwork {
public:
    Painting(std::string title, 
             std::string artist, 
             std::string style = "Unknown", 
             int year = 0);
    
    std::string getStyle() const { return style_; }
    int getYear() const { return year_; }
    std::string getInfo() const override;

private:
    std::string style_;
    int year_;
};