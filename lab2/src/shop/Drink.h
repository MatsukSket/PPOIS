#pragma once

#include "MenuItem.h"

class Drink : public MenuItem {
public:
    Drink(std::string name, double price, bool isHot = true);

    bool isHot() const { return isHot_; }
    std::string getType() const override { return "Drink"; }

private:
    bool isHot_;
    double caffeineMg_;
};