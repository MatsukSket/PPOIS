#include "shop/Drink.h"

Drink::Drink(std::string name, double price, bool isHot)
    : MenuItem(std::move(name), price), isHot_(isHot) {}