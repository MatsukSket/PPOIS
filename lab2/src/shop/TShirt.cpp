#include "shop/TShirt.h"

TShirt::TShirt(std::string name, double price, std::string size)
    : Souvenir(std::move(name), price), size_(std::move(size)) {}