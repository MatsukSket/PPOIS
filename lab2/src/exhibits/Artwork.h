#pragma once

#include <string>

class Artwork {
public:
    explicit Artwork(std::string title, std::string artist = "Unknown");
    virtual ~Artwork() = default;

    const std::string& title() const noexcept { return title_; }
    const std::string& artist() const noexcept { return artist_; }

    virtual std::string getInfo() const = 0;

private:
    std::string title_;
    std::string artist_;
    std::string creationYear_;
    std::string originCountry_;
    double insuranceValue_; 
};