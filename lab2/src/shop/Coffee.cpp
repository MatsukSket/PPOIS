#include "shop/Coffee.h"

Coffee::Coffee(std::string name, double price, std::string origin)
    : Drink(std::move(name), price, true), origin_(std::move(origin)) {}