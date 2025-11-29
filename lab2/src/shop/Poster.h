#include "Souvenir.h"

class Poster : public Souvenir {
public:
    Poster(std::string name, double price, std::string artist = "Unknown");
    
    const std::string& artist() const { return artist_; }
    std::string getCategory() const override { return "Poster"; }
private:
    std::string artist_;
    double widthCm_;
    double heightCm_;
};