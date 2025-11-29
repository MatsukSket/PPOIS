#include "shop/Dessert.h"

Dessert::Dessert(std::string name, double price, bool containsNuts)
    : MenuItem(std::move(name), price), containsNuts_(containsNuts) {}