#include "Drink.h"

class Smoothie : public Drink {
public:
    Smoothie(std::string name, double price, std::string fruit = "Mixed");
    
    const std::string& fruit() const { return fruit_; }
    std::string getType() const override { return "Smoothie"; }

private:
    std::string fruit_;
    std::string base_;
    bool hasAddedSugar_;
};