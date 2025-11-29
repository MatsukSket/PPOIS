#pragma once
#include "MenuItem.h"

class Dessert : public MenuItem {
public:
    Dessert(std::string name, double price, bool containsNuts = false);

    bool containsNuts() const { return containsNuts_; }
    std::string getType() const override { return "Dessert"; }

private:
    bool containsNuts_;
    double sugarGrams_;
    std::string topping_;
};