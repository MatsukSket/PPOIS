#include "shop/Souvenir.h"

Souvenir::Souvenir(std::string name, double price)
    : name_(std::move(name)), price_(price) {}