#pragma once

#include "MenuItem.h"
#include <string>

class MainCourse : public MenuItem {
public:
    MainCourse(std::string name, double price, std::string cuisine = "International");

    const std::string& cuisine() const { return cuisine_; }
    std::string getType() const override { return "MainCourse"; }

private:
    std::string cuisine_;
    std::string mainIngredient_;
    int proteinGrams_;
};