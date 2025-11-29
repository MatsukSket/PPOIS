#include "shop/Mug.h"

Mug::Mug(std::string name, double price, std::string material)
    : Souvenir(std::move(name), price), material_(std::move(material)) {}