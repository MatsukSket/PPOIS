#pragma once

#include "Artwork.h"
#include <string>

class Photograph : public Artwork {
public:
    Photograph(std::string title,
               std::string photographer,
               int year = 0,
               bool isColor = true);

    int year() const { return year_; }
    bool isColor() const { return isColor_; }

    std::string getInfo() const override;

private:
    int year_;
    bool isColor_;
};