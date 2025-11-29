#include "MenuItem.h"

MenuItem::MenuItem(std::string name, double price)
    : name_(std::move(name)), price_(price) {}